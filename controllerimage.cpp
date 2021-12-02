#include "controllerimage.h"

controllerImage::controllerImage(){
    qt = 0;
}

modelImage controllerImage::load_image(Glib::ustring nome_image){
            qt = 0;
            std::cout << nome_image << std::endl;
            Glib::RefPtr<Gdk::Pixbuf> load_img = Gdk::Pixbuf::create_from_file(nome_image,400,-1); 
            list_image[qt].set_ref_img(load_img,"Imagem Inicial");
            qt = 1;
            std::cerr << "teste" << '\n';
            return list_image[qt-1];
}

controllerImage::~controllerImage(){
    
}