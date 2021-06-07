#include "glew/include/glew.h"
#include "GLFW/include/glfw3.h"
#include <cstdio>
#include <cmath>
#include "DragonData.h"
#include "./GLShader.h"

#include "./Headers/Camera.h"
#include "./Headers/ObjLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./stb-master/stb_image.h"

GLuint Dragon3DProgram = 0;

void Initialize(GLFWwindow* window)
{
    printf("Version OPENGL : %s\n", glGetString(GL_VERSION));
    printf("Vendor : %s\n", glGetString(GL_VENDOR));
    printf("Renderer : %s\n", glGetString(GL_RENDERER));
    printf("Version GLSL : %s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("Erreur OpenGL, code %d\n", error);
    }

//    Dragon3DProgram = CreateShaderProgram(
//                            "./../Dragon3DLight.vs.glsl",
//                            "./../Dragon3DLight.fs.glsl");

}

void Terminate()
{
    DestroyProgram(Dragon3DProgram);
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Dragon", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    int width, height;
    glfwGetWindowSize(window, &width, &height);

    Camera camera = Camera(std::vector<float> {0, 0, 0}, 70.0f, 0.1f, 1000.0f, (float)width, (float)height);
    ObjLoader objLoader = ObjLoader("./../models/suzanne.obj");
    objLoader.load_obj();

    GLenum glewError = glewInit();
    if (glewError != GLEW_NO_ERROR)
    {
        glfwTerminate();
        return -1;
    }

    Initialize(window);

//    int h, w, nrChannels;
//    uint8_t *data = stbi_load("./../Textures/grass_grass_0070_03.jpg", &w, &h, &nrChannels, STBI_rgb_alpha);
//
//    GLuint texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//        stbi_image_free(data);
//    }

    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0, width, height);

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);



//        static const int stride = sizeof(float) * 8;
//
//        const int POSITION = glGetAttribLocation(
//                            Dragon3DProgram,
//                            "a_position");
//        glEnableVertexAttribArray(POSITION);
//        glVertexAttribPointer(POSITION, 3, GL_FLOAT
//                , false, stride, &DragonVertices[0]);
//
//        const int NORMAL = glGetAttribLocation(
//                            Dragon3DProgram,
//                            "a_normal");
//        glEnableVertexAttribArray(NORMAL);
//        glVertexAttribPointer(NORMAL, 3, GL_FLOAT
//                        , false, stride, &DragonVertices[3]);
//
//        const GLint texAttrib = glGetAttribLocation(Dragon3DProgram,"a_texcoords");
//        glEnableVertexAttribArray(texAttrib);
//        glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, stride, &DragonVertices[6]);

        glEnableVertexAttribArray(attribute_v_coord);
        // Describe our vertices array to OpenGL (it can't guess its format automatically)
        glBindBuffer(GL_ARRAY_BUFFER, vbo_mesh_vertices);
        glVertexAttribPointer(
                attribute_v_coord,  // attribute
                4,                  // number of elements per vertex, here (x,y,z,w)
                GL_FLOAT,           // the type of each element
                GL_FALSE,           // take our values as-is
                0,                  // no extra data between each position
                0                   // offset of first element
        );

        glEnableVertexAttribArray(attribute_v_normal);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_mesh_normals);
        glVertexAttribPointer(
                attribute_v_normal, // attribute
                3,                  // number of elements per vertex, here (x,y,z)
                GL_FLOAT,           // the type of each element
                GL_FALSE,           // take our values as-is
                0,                  // no extra data between each position
                0                   // offset of first element
        );

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_mesh_elements);

//        glUseProgram(Dragon3DProgram);
//
//        float time = glfwGetTime();
//        const int timeLocation = glGetUniformLocation(
//                    Dragon3DProgram,
//                    "u_time");
//        glUniform1f(timeLocation, time);
//
//        float rotationMatrix[] = {
//            cosf(time), 0.f, -sinf(time), 0.0f,
//            0.0f, 1.0f, 0.0f, 0.f,
//            sinf(time), 0.f, cosf(time), 0.0f,
//            0.0f, 0.0f, 0.0f, 1.0f
//        };
//
//        const int rotationLocation = glGetUniformLocation(
//                    Dragon3DProgram,
//                    "u_rotationMatrix"
//        );
//
//        glUniformMatrix4fv(rotationLocation,
//                            1,
//                            GL_TRUE,
//                            rotationMatrix
//                            );
//
//        float translationMatrix[] = {
//            1.0f, 0.0f, 0.0f, 0.0f,
//            0.0f, 1.0f, 0.0f, 0.0f,
//            0.0f, 0.0f, 1.0f, 0.0f,
//            cosf(time), 0.0f, -20.0f, 1.0f
//        };
//
//        const int translationLocation = glGetUniformLocation(
//                    Dragon3DProgram,
//                    "u_translationMatrix"
//        );
//
//        glUniformMatrix4fv(translationLocation,
//                            1,
//                            GL_FALSE,
//                            translationMatrix
//                            );
//
//        float projectionMatrix[] = {
//                camera.getCot()/camera.getAspect(), 0.0f, 0.0f, 0.0f,
//                0.0f, camera.getCot(), 0.0f, 0.0f,
//                0.0f, 0.0f, -(camera.getZNear()+camera.getZFar())/(camera.getZFar()-camera.getZNear()), -1.0f,
//                0.0f, 0.0f, -(2.0f*camera.getZNear()*camera.getZFar())/(camera.getZFar()-camera.getZNear()), 0.0f
//        };
//
//        const int projectionLocation = glGetUniformLocation(
//                    Dragon3DProgram,
//                    "u_projectionMatrix"
//        );
//
//        glUniformMatrix4fv(projectionLocation,
//                            1,
//                            GL_FALSE,
//                            projectionMatrix
//                            );
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture);
//
        int size;
        glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);

        glDrawElements(GL_TRIANGLES,
                    sizeof(DragonIndices) / sizeof(short)
                                , GL_UNSIGNED_SHORT,
                                DragonIndices);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Terminate();
    glfwTerminate();
    return 0;
}
