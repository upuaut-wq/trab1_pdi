#include <iostream>
#include "modelimage.h"

modelImage::modelImage(){
 
}

void modelImage::set_nome_img(Glib::ustring nome_img,Glib::ustring filtro){
    this->filtro = filtro;
    this->nome_img = nome_img;
}

Glib::ustring modelImage::get_nome_img(){
    return this->nome_img;
}

Glib::ustring modelImage::get_filtro(){
    return this->filtro;
}


modelImage::~modelImage(){
    
}