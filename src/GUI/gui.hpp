#pragma once
#include <imgui.h>
#include "glm/fwd.hpp"



class GUI{
    private:
        static float     alignement_force;             
        static float     separation_force;
        static float     cohesion_force;   


    public:

        static void initializeGUI();

};