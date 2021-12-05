#ifndef GTKMM_CONTROLLERIMAGE_H
#define GTKMM_CONTROLLERIMAGE_H

#define MAX_IMG 30

#include <gtkmm/image.h>
#include <iostream>
#include "../model/modelimage.h"

class controllerImage{
    public:
        int qt;
        modelImage list_image[MAX_IMG];


        controllerImage();
        modelImage load_image(Glib::ustring nome_image);
        modelImage get_list_image();
        ~controllerImage();
};
#endif //GTKMM_CONTROLLERIMAGE_H
