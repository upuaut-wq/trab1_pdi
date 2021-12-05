#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/scale.h>
#include <gtkmm/separator.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/image.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/togglebutton.h>
#include <gdkmm/pixbuf.h>
#include <glibmm/refptr.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/filechooserbutton.h>
#include "../controller/controllerimage.h"
#include <gtkmm/radiobutton.h>
#include "../controller/controlleralgoritmos.h"
#include <gtkmm/grid.h>


class mainWindow:public Gtk::Window{
    public:
        controllerImage *ci;
        controllerAlgoritmos *ca;

        mainWindow();
        void cria_menu_superior();
        void cria_janela_config();
        void cria_menu_inferior();
        void cria_image(); 
        void cria_lista(); 
        void cria_interface_algoritmos();
        void set_algoritmo_config();
        virtual ~mainWindow();
    protected:
        //Widgets Janela
        Gtk::Box m_box_main;
        Gtk::Separator m_sep_main;
        Gtk::Box m_box_trab;
        Gtk::Box m_box_esq;
        Gtk::Separator m_sep_trab;
        Gtk::Box m_box_dir;
        
        //Menu superior
        Gtk::Box m_box_sup_menu;
        Gtk::Entry m_ent_load_img;
        Gtk::Button m_btn_load_img;
        Gtk::Separator m_sep_sup;
        Gtk::Button m_nov_filt;

        //Menu inferior
        Gtk::Separator m_sep_inf;
        Gtk::Box m_box_inf_menu;
        Gtk::Label m_label_hist;

        //Janela de configurações
        Gtk::Box m_box_conf;
        Gtk::Box m_box_aplic;
        Gtk::Button m_btn_aplic;
        Gtk::Button m_btn_algo;
        Gtk::Frame m_frm_conf;
        Gtk::Label m_lab_jan_conf;

        //Image
        Gtk::Image m_img;
        Gtk::Label m_label;
        Glib::RefPtr<Gdk::Pixbuf> m_ref_img;

        //Sinais
        void on_load_image();
        void on_novo_filt();

        //Configuração de algoritmos
        //Lista de algoritmos
        Gtk::Label m_label_list;
        Gtk::Separator m_sep_list;
        Gtk::Box m_box_list;
        Gtk::Box m_box_alg;
        Gtk::RadioButtonGroup m_grupo_rb;
        Gtk::RadioButton m_radio_btns[16];

        //Interface algorimo Limiarizacao
        Gtk::Label m_lb_lim;
        Gtk::Scale m_scl_lim;
        Gtk::CheckButton m_chb_lim;
        Gtk::Box m_box_lim;
        Gtk::Separator m_sep_lim;
        Gtk::Button m_btn_lim;
        void interf_config_limi();
        void on_aplic_lim();
       

        //Sinal Escolhe e muda tela para configuração
        void on_config_algo();



        
};

#endif //GTKMM_MAINWINDOW_H