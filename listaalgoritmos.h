#ifndef GTKMM_LISTAALGORITMOS_H
#define GTKMM_LISTAALGORITMOS_H
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/separator.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>

class listaAlgoritmos:public Gtk::Box{
    public:
        listaAlgoritmos();
        virtual ~listaAlgoritmos();
    private:
        Gtk::Label m_label;
        Gtk::Separator m_sep;
        Gtk::Box m_box;
};


#endif //GTKMM_LISTAALGORITMOS_H

