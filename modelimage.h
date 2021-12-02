#ifndef GTKMM_MODELIMAGE_H
#define GTKMM_MODELIMAGE_H
#include <glibmm/refptr.h>
#include <gdkmm/pixbuf.h>

#include <iostream>

class modelImage{
    private:
        Glib::RefPtr<Gdk::Pixbuf> ref_img;
        Glib::ustring filtro;
    public:
        modelImage();
        void set_ref_img(Glib::RefPtr<Gdk::Pixbuf> ref_img,Glib::ustring filtro);
        Glib::RefPtr<Gdk::Pixbuf> get_ref_img();
        Glib::ustring get_filtro();
        ~modelImage();
};

#endif //GTKMM_MODELIMAGE_H