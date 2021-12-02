#include <iostream>
//#include "controllerimage.h"
#include "mainWindow.h"

mainWindow::mainWindow(){
    //Instancia
    this->ci = new controllerImage();

    //Janela principal
    this->set_title("PDI");
    this->set_border_width(2);
    this->maximize();

     //Box principal
    
    this->m_box_main.set_homogeneous(false);
    this->m_box_main.set_spacing(3);
    this->m_box_main.set_orientation(Gtk::ORIENTATION_VERTICAL); 
    this->m_box_trab.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_box_dir.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box_dir.set_halign(Gtk::ALIGN_END);

    this->add(this->m_box_main);
        this->m_box_main.pack_start(this->m_box_sup_menu,Gtk::PACK_SHRINK);
        this->m_box_main.pack_start(this->m_sep_main,Gtk::PACK_SHRINK);
        this->m_box_main.pack_start(this->m_box_trab,Gtk::PACK_EXPAND_WIDGET);
            this->m_box_trab.pack_start(this->m_box_esq,Gtk::PACK_EXPAND_WIDGET);
            this->m_box_trab.pack_start(this->m_sep_trab,Gtk::PACK_SHRINK);
            this->m_box_trab.pack_start(this->m_box_dir,Gtk::PACK_SHRINK);
        this->m_box_main.pack_start(this->m_box_inf_menu,Gtk::PACK_SHRINK);

    //Cria Menu Superior
    this->cria_menu_superior();

    //Cria Janlena de configurações
    this->cria_janela_config();

    //Image
    cria_image();
    
    //Lista de algoritmos
    this->cria_lista();

    //Cria menu inferior
    this->cria_menu_inferior();

    //Cria Sinal Botoão load image
    this->m_btn_load_img.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_load_image));

    //Signal novo filtro
    this->m_nov_filt.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_novo_filt));

    //Mostra tudo
    this->show_all_children();
}

mainWindow::~mainWindow(){

}

void mainWindow::cria_menu_superior(){
     //Confgura btn_load_image
    this->m_btn_load_img.set_label("Carregar Imagem");
    this->m_btn_load_img.set_always_show_image(true);
    this->m_btn_load_img.set_image_from_icon_name("add-folder-to-archive",Gtk::ICON_SIZE_BUTTON);

    //Configura Entry Load Image
    this->m_ent_load_img.set_tooltip_text("Nome da imagem ex: \n /folder/img.png");

    //Configura separator superior
    this->m_sep_sup.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_sep_sup.set_visible(true);

    //Configura botão novo filtro
    this->m_nov_filt.set_label("Novo Filtro");
    this->m_nov_filt.set_always_show_image(true);
    this->m_nov_filt.set_image_from_icon_name("add",Gtk::ICON_SIZE_BUTTON);
    this->m_nov_filt.set_tooltip_text("Alplica Novo Filtro na Imagem");

    //Menu Superior
    this->m_box_sup_menu.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_box_sup_menu.pack_start(this->m_ent_load_img);
    this->m_box_sup_menu.pack_start(this->m_btn_load_img);
    this->m_box_sup_menu.pack_start(this->m_sep_sup);
    this->m_box_sup_menu.pack_start(this->m_nov_filt);
    this->m_box_sup_menu.set_halign(Gtk::ALIGN_START);
}

void mainWindow::cria_janela_config(){
    this->m_box_dir.pack_start(this->m_box_conf,Gtk::PACK_SHRINK);
    this->m_box_dir.pack_end(this->m_box_aplic);

    //Confgura botão
    this->m_box_aplic.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box_aplic.pack_start(m_btn_aplic);
    this->m_btn_aplic.set_label("AplicarConfiguração");
    this->m_btn_aplic.set_always_show_image(true);
    this->m_btn_aplic.set_image_from_icon_name("gtk-apply",Gtk::ICON_SIZE_BUTTON);
    this->m_btn_aplic.set_halign(Gtk::ALIGN_END);
    this->m_box_aplic.set_valign(Gtk::ALIGN_END);
}

void mainWindow::cria_image(){
    this->m_box_esq.set_border_width(10);
    this->m_box_esq.pack_start(this->m_img);
    this->m_img.set_valign(Gtk::ALIGN_START);
    this->m_box_esq.pack_start(this->m_label);
    this->m_box_esq.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Imagem padrão
    this->m_label.set_text("Carregar Imagem");
    Glib::RefPtr<Gdk::Pixbuf> ref_img_p = Gdk::Pixbuf::create_from_file("img_init.png");
    this->m_img.set(ref_img_p);
}

void mainWindow::cria_menu_inferior(){
    this->m_box_inf_menu.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box_inf_menu.set_size_request(-1,30);
    this->m_box_inf_menu.pack_start(this->m_sep_inf,Gtk::PACK_SHRINK);
    this->m_box_inf_menu.pack_start(this->m_label_hist);
    this->m_label_hist.set_text("FILTROS ▶ Abrir Imagem");
    this->m_label_hist.set_halign(Gtk::ALIGN_START);

}

 void set__algoritmo_config(){
     std::cout << "Janel Principal" << std::endl;
 }

//SINAIS=======================================================

void mainWindow::on_load_image(){
    Glib::ustring nome_img = this->m_ent_load_img.get_text();
    modelImage img = ci->load_image(nome_img);
        std::cerr << "Imagem ok" << std::endl;
        this->m_img.set(img.get_ref_img());
        this->m_label.set_text(img.get_filtro());
        this->m_label_hist.set_text("FILTROS ▶" + img.get_filtro());
}

void mainWindow::on_novo_filt(){
    
}

//Algoritmos

void mainWindow::cria_lista(){
    this->m_label_list.set_text("Algoritmo");
    this->m_box_list.set_border_width(10);
    this->m_label_list.set_valign(Gtk::ALIGN_START);
    this->m_label_list.set_size_request(50,30);
    this->m_box_list.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box_list.pack_start(this->m_label_list);
    this->m_box_list.pack_start(this->m_sep_list);
    for(int i = 0 ; i < 10; i++){
        Gtk::Button *btn = new Gtk::Button();
        btn->set_relief(Gtk::RELIEF_NONE);
        this->m_box_list.pack_start(*btn);
        btn->set_label("Label" + i);
    }
    this->m_box_conf.pack_start(this->m_box_list);
}