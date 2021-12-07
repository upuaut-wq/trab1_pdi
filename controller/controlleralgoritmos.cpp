#include "controlleralgoritmos.h"
#include <iostream>

controllerAlgoritmos::controllerAlgoritmos()
{
}

void controllerAlgoritmos::execute_limiarizacao(float threshold, bool moment, controllerImage *contImg)
{
    //Inicia interpretador
    try
    {
        int status = this->interpreter.execute();
        if (status != 0)
        {
            std::cerr << "Erro ao inicializar o Interpretador Octave" << std::endl;
        }
        else
        {
            //Executa algoritmo
            //this->load_pack_image();
            octave_value_list load_p;
            load_p(0) = octave_value("load");  //Argumento load
            load_p(1) = octave_value("image"); //Argumento image(Pacote)
            octave::feval("pkg", load_p);      //Chama o comando pkg com a lista de argumentos
            //Executa normal
            octave_value_list readimg;
            std::string nome_img = contImg->list_image[contImg->qt - 1].get_nome_img();

            //Le imagem
            readimg(0) = nome_img;

            //Executa o imread(img)
            octave_value_list img_octave;
            img_octave(0) = octave_value(octave::feval("imread", readimg(0)));

            //Aplica filtro
            octave_value_list param = octave_value(img_octave(0));
            octave_value_list out_img;
            if (moment != true){
                std::cout << threshold << std::endl;
                param(1) = threshold;
            }else{
                param(1) = octave_value("moments");
            }
            out_img(0) = octave_value(octave::feval("im2bw", param,1));

            //Salva Imagem
            //Cria a lista de argumentos para salvar a imagem
            octave_value_list save;
            save(0) = octave_value(out_img(0));
            save(1) = octave_value("image" + contImg->qt);
            save(2) = octave_value("png");
            octave::feval("imwrite", save, 2); //Salva a imagem com a lista de argumentos n2

            //Atualiza controller Image

            contImg->list_image[contImg->qt].set_nome_img("image" + contImg->qt, "Limiarizacao");
            contImg->qt++;
        
        }
    }
    catch (const octave::exit_exception &ex)
    {
        std::cerr << "Octave interpreter exited with status = " << ex.exit_status() << std::endl;
    }
    catch (const octave::execution_exception &)
    {
        std::cerr << "error encountered in Octave evaluator!" << std::endl;
    }
}

controllerAlgoritmos::~controllerAlgoritmos()
{
}

void controllerAlgoritmos::load_pack_image()
{
    //Lista de argumentos para o comando pkg
    octave_value_list load_p;
    load_p(0) = octave_value("load");  //Argumento load
    load_p(1) = octave_value("image"); //Argumento image(Pacote)
    octave::feval("pkg", load_p);      //Chama o comando pkg com a lista de argumentos
}
