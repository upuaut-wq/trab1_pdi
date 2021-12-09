#ifndef OCTAVE_CONTROLLERALGORITMOS_H
#define OCTAVE_CONTROLLERALGORITMOS_H

#include <octave-5.2.0/octave/oct.h>
#include <octave-5.2.0/octave/octave.h>
#include <octave-5.2.0/octave/parse.h>
#include <octave-5.2.0/octave/interpreter.h>
#include <octave-5.2.0/octave/octave-default-image.h>
#include "../model/modelimage.h"
#include "../controller/controllerimage.h"


class controllerAlgoritmos{
    private:
        octave::interpreter interpreter;
        octave_value_list list_image;
    public:
        controllerAlgoritmos();
        void load_pack_image();
        boolean write_img(modelImage img);
        boolean execute_limiarizacao(float threshold, bool moment, modelImage img);
        ~controllerAlgoritmos();
};


#endif  //OCTAVE_CONTROLLERALGORITMOS_H