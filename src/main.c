#include <gtk/gtk.h>
#include <webkit/webkit.h>

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    WebKitWebView *webview;

    window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "Messenger");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);

    webview = WEBKIT_WEB_VIEW(webkit_web_view_new());

    gtk_window_set_child(GTK_WINDOW(window), GTK_WIDGET(webview));

    webkit_web_view_load_uri(
        webview,
        "https://www.messenger.com/"
    );

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "io.github.yesse.MessengerLinux",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(
        app,
        "activate",
        G_CALLBACK(activate),
        NULL
    );

    status = g_application_run(
        G_APPLICATION(app),
        argc,
        argv
    );

    g_object_unref(app);

    return status;
}
