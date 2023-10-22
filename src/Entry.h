//
// Created by stmihan on 10/23/2023.
//
#ifndef SIME_MAIN_CPP
#define SIME_MAIN_CPP

#include "app/Application.h"

namespace Sime {
    int entryPoint(Sime::Application *sandbox) {
        sandbox->run();
        delete sandbox;
        return 0;
    }
}

#endif //SIME_MAIN_CPP
