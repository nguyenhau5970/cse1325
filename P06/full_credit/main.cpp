#include "mainwin.h"
#include <gtkmm.h>

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "P06 Sprint 2 SMART");
    Mainwin win;
    return app->run(win);
}