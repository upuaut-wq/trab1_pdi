#include <iostream> 
//#include "controllerimage.h"
#include "mainWindow.h"

mainWindow::mainWindow(){
    //Instancia do controllerImage, controllerAlgorimos
    this->ci = new controllerImage();
    this->ca = new controllerAlgoritmos();

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

    //Empacotamento principal
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
    this->cria_image();
    
    //Lista de algoritmos
    this->cria_lista();

    //Cria menu inferior
    this->cria_menu_inferior();

    this->cria_interface_algoritmos();

    //Cria Sinal Botoão load image
    this->m_btn_load_img.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_load_image));

    //Signal novo filtro
    this->m_nov_filt.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_novo_filt));

    //cria sinal configurar
    this->m_btn_algo.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_config_algo));

    //Mostra tudo
    this->show_all();

    //Motra tudo menos
    this->m_btn_aplic.hide();
    this->m_box_list.hide();
}

mainWindow::~mainWindow(){

}

//Cria menu superior(Carrega a imagem)
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

    //Menu Empactora e adiciona posição e orientação
    this->m_box_sup_menu.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_box_sup_menu.pack_start(this->m_ent_load_img);
    this->m_box_sup_menu.pack_start(this->m_btn_load_img);
    this->m_box_sup_menu.pack_start(this->m_sep_sup);
    this->m_box_sup_menu.pack_start(this->m_nov_filt);
    this->m_box_sup_menu.set_halign(Gtk::ALIGN_START);
}

//Cria a janela direita
//-> Aparece lista de Algorimos
//-> Configuração dos algoritmos
void mainWindow::cria_janela_config(){
    this->m_box_dir.pack_start(this->m_box_conf,Gtk::PACK_SHRINK);
}

//Apresenta a imagem padrao na tela.
void mainWindow::cria_image(){
    this->m_box_esq.set_border_width(10);
    this->m_box_esq.pack_start(this->m_img);
    this->m_img.set_valign(Gtk::ALIGN_START);
    this->m_box_esq.pack_start(this->m_label);
    this->m_box_esq.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Imagem padrão
    this->m_label.set_text("Carregar Imagem");
    Glib::RefPtr<Gdk::Pixbuf> ref_img_p = Gdk::Pixbuf::create_from_file("img/img_init.png");
    this->m_img.set(ref_img_p);
}

//Cria menu inferior, apresenta a sequencia de filtros aplicados
void mainWindow::cria_menu_inferior(){
    this->m_box_inf_menu.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box_inf_menu.set_size_request(-1,30);
    this->m_box_inf_menu.pack_start(this->m_sep_inf,Gtk::PACK_SHRINK);
    this->m_box_inf_menu.pack_start(this->m_label_hist);
    this->m_label_hist.set_text("FILTROS ▶ Abrir Imagem");
    this->m_label_hist.set_halign(Gtk::ALIGN_START);

}

//Cria a Lista de algoritmos com os devidos nomes.
void mainWindow::cria_lista(){
    Glib::ustring nomes[] = {"Algorimo1","Limiarização","Escala de Cinza","Passa-Alta","Passa-Baixa","Roberts","Prewitt","Sobel","Log","Zerocross","Canny","Ruídos","Watershed","Histograma","Ajuste adaptativo de histograma","Cont limiarizados"};
    this->m_label_list.set_text("Algoritmo");
    this->m_box_list.set_border_width(10);
    this->m_label_list.set_valign(Gtk::ALIGN_START);
    this->m_label_list.set_margin_bottom(10);
    this->m_box_list.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Empacota
    this->m_box_list.pack_start(this->m_label_list);
    this->m_box_list.pack_start(this->m_sep_list);
    this->m_box_list.pack_start(this->m_box_alg);
    this->m_box_alg.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Configura botoes
    for(int i = 0 ; i < 16; i++){
        this->m_radio_btns[i].set_label(nomes[i]);
        this->m_box_alg.pack_start(this->m_radio_btns[i]);
        this->m_radio_btns[i].set_group(this->m_grupo_rb);
    }
    this->m_box_conf.pack_start(this->m_box_list);
}


    void mainWindow::cria_interface_algoritmos(){
        //Limiarização
        this->interf_config_limi();
    }

//Interface de configuração Algoritmos
    void mainWindow::interf_config_limi(){
        this->m_box_lim.pack_start(this->m_lb_lim,Gtk::PACK_SHRINK);
        this->m_box_lim.pack_start(this->m_sep_lim,Gtk::PACK_SHRINK);
        this->m_box_lim.pack_start(this->m_scl_lim,Gtk::PACK_SHRINK);
        this->m_box_lim.pack_start(this->m_chb_lim,Gtk::PACK_SHRINK);
        this->m_box_lim.pack_start(this->m_btn_lim);
        this->m_box_lim.set_orientation(Gtk::ORIENTATION_VERTICAL);
        this->m_scl_lim.set_size_request(200);


        this->m_btn_lim.set_label("Aplicar");
        this->m_btn_lim.set_halign(Gtk::ALIGN_END);
        this->m_lb_lim.set_label("Limiarização");
        this->m_scl_lim.set_range(0,1);
        this->m_scl_lim.set_digits(2);
        this->m_scl_lim.set_value_pos(Gtk::POS_RIGHT);
        this->m_chb_lim.set_label(" : Usar 'moments'");

        this->m_box_conf.pack_start(this->m_box_lim,Gtk::PACK_EXPAND_WIDGET);
        this->m_btn_lim.signal_clicked().connect(sigc::mem_fun0(*this,&mainWindow::on_aplic_lim));
    }



//SINAIS=======================================================

//Carrega imagem de acordo com o caminho descrito na Gtk::Entry
void mainWindow::on_load_image(){
    Glib::ustring nome_img = this->m_ent_load_img.get_text();
    modelImage img = ci->load_image(nome_img);
    this->m_ref_img = Gdk::Pixbuf::create_from_file("img/"+nome_img,400,-1); 
    this->m_img.set(this->m_ref_img);
    this->m_label.set_text(img.get_filtro());
    this->m_label_hist.set_text("FILTROS ▶" + img.get_filtro());
    
}


//Mostra a Janela Novo filtro quando estiver oculta.
void mainWindow::on_novo_filt(){
    this->m_box_list.show();
}

//Verifica qual Radio Button esta ativo
void mainWindow::on_config_algo(){
    int i = 0;
    int alg = 0;
    while(i < 16){
        if(this->m_radio_btns[i].get_active() == true){
            alg = i;
            break;
        }
        i++;
    }
    std::cout << "Algo " << alg << std::endl; 
    
}

void mainWindow::on_aplic_lim(){
    float threshold = this->m_scl_lim.get_value();
    bool use_moments = this->m_chb_lim.get_active();

    this->ca->execute_limiarizacao(threshold,use_moments,this->ci);

    this->m_ref_img = Gdk::Pixbuf::create_from_file(this->ci->list_image[this->ci->qt-1].get_nome_img(),400,-1); 
    this->m_img.set(this->m_ref_img);
    this->m_label.set_text(this->ci->list_image[this->ci->qt-1].get_filtro());
}
