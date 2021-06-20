//
// Created by berthelot Mickael on 11/05/2021.
//

#include "../Headers/ObjLoader.h"

void ObjLoader::load_obj() const {

    FILE *file = fopen(this->filename, "rb");

    if (file == nullptr) {
        printf("Error happened when tried to open this file...");
        fclose(file);
        return;
    }

    while (true) {

        char line[1024];

        int res = fscanf(file, "%s", line);

        if (res == EOF) {
            fclose(file);
            break;
        }

        if (strcmp(line, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            this->data->vertices.push_back(vertex);
        } else if (strcmp(line, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f %f\n", &uv.x, &uv.y);
            this->data->uvs.push_back(uv);
        } else if (strcmp(line, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            this->data->normals.push_back(normal);
        } else if (strcmp(line, "f") == 0) {

//            std::string vertex1, vertex2, vertex3, vertex4;
//            float vertexIndex[3], uvIndex[3], normalIndex[3];
//
//            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",
//                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
//                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
//                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
////                                 &vertexIndex[3], &uvIndex[3], &normalIndex[3]);
//
//            printf("%d matches \n", matches);
//            printf("%d %d %d \n", vertexIndex[0], uvIndex[0], normalIndex[0]);
//            printf("%d %d %d \n", vertexIndex[1], uvIndex[1], normalIndex[1]);
//            printf("%d %d %d \n", vertexIndex[2], uvIndex[2], normalIndex[2]);
//            if (matches != 12 && matches != 9) {
//                printf("This file cannot be read by this loader...");
//                return;
//            }
//
//            this->data->vertexIndices.push_back(vertexIndex[0]);
//            this->data->vertexIndices.push_back(vertexIndex[1]);
//            this->data->vertexIndices.push_back(vertexIndex[2]);
//            this->data->uvIndices.push_back(uvIndex[0]);
//            this->data->uvIndices.push_back(uvIndex[1]);
//            this->data->uvIndices.push_back(uvIndex[2]);
//            this->data->normalIndices.push_back(normalIndex[0]);
//            this->data->normalIndices.push_back(normalIndex[1]);
//            this->data->normalIndices.push_back(normalIndex[2]);
//²
//            if (matches == 12) {
//                this->data->vertexIndices.push_back(vertexIndex[0]);
//                this->data->vertexIndices.push_back(vertexIndex[2]);
//                this->data->vertexIndices.push_back(vertexIndex[3]);
//                this->data->uvIndices.push_back(uvIndex[0]);
//                this->data->uvIndices.push_back(uvIndex[2]);
//                this->data->uvIndices.push_back(uvIndex[3]);
//                this->data->normalIndices.push_back(normalIndex[0]);
//                this->data->normalIndices.push_back(normalIndex[2]);
//                this->data->normalIndices.push_back(normalIndex[3]);
//            }
        }
    }

    fclose(file);
}
