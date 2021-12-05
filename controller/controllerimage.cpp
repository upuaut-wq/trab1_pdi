#include "controllerimage.h"

controllerImage::controllerImage(){
    qt = 0;
}

modelImage controllerImage::load_image(Glib::ustring nome_image){
            qt = 0;
            std::cout << nome_image << std::endl;
            list_image[qt].set_nome_img(nome_image,"Imagem Inicial");
            qt = 1;
            std::cerr << "teste" << '\n';
            return list_image[qt-1]; 
}

controllerImage::~controllerImage(){
    
}
