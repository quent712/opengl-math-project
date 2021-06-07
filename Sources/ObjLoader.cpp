//
// Created by berthelot Mickael on 11/05/2021.
//

#include "../Headers/ObjLoader.h"

void ObjLoader::load_obj() const{

    std::ifstream file(this->filename);
    std::string line;
    std::istringstream contentLine;
    while(std::getline(file, line)) {
        if (line.substr(0,2) == "v ") {
            contentLine.str(line.substr(2));
            glm::vec4 v;
            contentLine >> v.x;
            contentLine >> v.y;
            contentLine >> v.z;
            v.w = 1.0f;
            this->data->vertices.push_back(v);
        } else if (line.substr(0,2) == "f ") {
            contentLine.str(line.substr(2));
            GLushort a,b,c;
            contentLine >> a;
            contentLine >> b;
            contentLine >> c;
            a--; b--; c--;
            this->data->elements.push_back(a);
            this->data->elements.push_back(b);
            this->data->elements.push_back(c);
        }
        contentLine.clear();
    }

    this->data->normals.resize(this->data->vertices.size(), glm::vec3(0.0, 0.0, 0.0));

    for (int i = 0; i < this->data->elements.size(); i++)
    {
        GLushort ia = this->data->elements[i];
        GLushort ib = this->data->elements[i+1];
        GLushort ic = this->data->elements[i+2];

        glm::vec3 normal = glm::normalize(glm::cross(
                glm::vec3(this->data->vertices[ib]) - glm::vec3(this->data->vertices[ia]),
                glm::vec3(this->data->vertices[ic]) - glm::vec3(this->data->vertices[ia])
                ));

        this->data->normals[ia] = this->data->normals[ic] = this->data->normals[ib] = normal;
    }
}

