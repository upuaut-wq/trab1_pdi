#include <iostream>
#include "modelimage.h"

modelImage::modelImage(){
 
}

void modelImage::set_ref_img(Glib::RefPtr<Gdk::Pixbuf> ref_img,Glib::ustring filtro){
    this->filtro = filtro;
    this->ref_img = ref_img;
}

Glib::RefPtr<Gdk::Pixbuf> modelImage::get_ref_img(){
    return this->ref_img = ref_img;
}

Glib::ustring modelImage::get_filtro(){
    return this->filtro;
}


modelImage::~modelImage(){
    
}