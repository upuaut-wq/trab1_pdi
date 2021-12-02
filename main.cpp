#include <gtkmm/application.h>
#include "mainWindow.h"


int main(int argc, char * argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"PDI.Computacao.Trab");
    mainWindow main_window;
    app->run(main_window);
}