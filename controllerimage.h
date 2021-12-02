#ifndef GTKMM_CONTROLLERIMAGE_H
#define GTKMM_CONTROLLERIMAGE_H

#define MAX_IMG 30

#include <gtkmm/image.h>
#include <iostream>
#include "modelimage.h"

class controllerImage{
    private:
         int qt;
         //Glib::ustring ṕarei aqui
         modelImage list_image[MAX_IMG];
    public:
        controllerImage();
        modelImage load_image(Glib::ustring nome_image);
        ~controllerImage();
};
#endif //GTKMM_CONTROLLERIMAGE_H
