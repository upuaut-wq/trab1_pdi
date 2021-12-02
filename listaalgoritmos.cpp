#include "listaalgoritmos.h"

listaAlgoritmos::listaAlgoritmos(){
    this->add(this->m_box);
    this->set_size_request(200);
    this->set_border_width(5);
    this->m_label.set_text("Algoritmo");
     this->m_label.set_size_request(50,30);
    this->m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box.pack_start(this->m_label);
    this->m_box.pack_start(this->m_sep);
    for(int i = 0 ; i < 10; i++){
        Gtk::Button *btn = new Gtk::Button();
        btn->set_relief(Gtk::RELIEF_NONE);
        this->m_box.pack_start(*btn);
        btn->set_label("Label" + i);
    }
    this->show_all_children();
    
}


listaAlgoritmos::~listaAlgoritmos(){

}