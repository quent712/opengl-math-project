//
// Created by berthelot Mickael on 11/05/2021.
//

#ifndef OPENGL_PROJECT_OBJLOADER_H
#define OPENGL_PROJECT_OBJLOADER_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../glew/include/glew.h"
#include <list>

#include "./glm/glm.hpp"
#include "./glm/vec3.hpp"
#include "./glm/vec4.hpp"

typedef struct DataObj {
    std::vector<glm::vec3> normals;
    std::vector<GLushort> elements;
    std::vector<glm::vec4> vertices;
} DataObj;

class ObjLoader {
public:
    ObjLoader(std::string filename) : filename(filename)
    {
        this->data = new DataObj();
    };
    void load_obj() const;

    DataObj *data;

    std::string filename;
};


#endif //OPENGL_PROJECT_OBJLOADER_H
