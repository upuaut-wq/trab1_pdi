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
#include "controllerimage.h"
#include "listaalgoritmos.h"



class mainWindow:public Gtk::Window{
    public:
        controllerImage *ci;

        mainWindow();
        void cria_menu_superior();
        void cria_janela_config();
        void cria_menu_inferior();
        void cria_image();
        void set__algoritmo_config();
        virtual ~mainWindow();
    protected:
        //Widgets
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
        Gtk::Frame m_frm_conf;
        Gtk::Label m_lab_jan_conf;

        //Image
        Gtk::Image m_img;
        Gtk::Label m_label;

        //Sinais
        void on_load_image();
        void on_novo_filt();

        //Configuração de algoritmos
        //Lista de algoritmos
        Gtk::Label m_label_list;
        Gtk::Separator m_sep_list;
        Gtk::Box m_box_list;
        void cria_lista();



        
};

#endif //GTKMM_MAINWINDOW_H