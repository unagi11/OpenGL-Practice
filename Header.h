//
//  Header.h
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/24.
//

#define GL_SILENCE_DEPRECATION

#ifdef _WIN32
#include "glut.h"
#elif __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <iostream>
