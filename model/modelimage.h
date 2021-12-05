#ifndef GTKMM_MODELIMAGE_H
#define GTKMM_MODELIMAGE_H
#include <glibmm/refptr.h>
#include <gdkmm/pixbuf.h>

#include <iostream>

class modelImage{
    private:
        Glib::ustring nome_img;
        Glib::ustring filtro;
    public:
        modelImage();
        void set_nome_img(Glib::ustring nome_img,Glib::ustring filtro);
        Glib::ustring get_nome_img();
        Glib::ustring get_filtro();
        ~modelImage();
};

#endif //GTKMM_MODELIMAGE_H