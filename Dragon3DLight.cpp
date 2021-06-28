#include "glew/include/glew.h"
#include "GLFW/include/glfw3.h"
#include <cstdio>
#include "GLShader.h"
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

    Dragon3DProgram = CreateShaderProgram(
                            "./../Dragon3DLight.vs.glsl",
                            "./../Dragon3DLight.fs.glsl");

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

    GLenum glewError = glewInit();
    if (glewError != GLEW_NO_ERROR)
    {
        glfwTerminate();
        return -1;
    }

    Initialize(window);

    Camera camera = Camera(std::vector<float> {0, 0, 0}, 70.0f, 0.1f, 1000.0f, (float)width, (float)height);
    ObjLoader objLoader = ObjLoader("./../models/suzanne.obj");
    objLoader.load_obj();

//    GLuint triangleVBO;
//    glGenBuffers(1, &triangleVBO);
//    glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(objLoader.data->vertices.size()), &objLoader.data->vertices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window))
    {
//        glViewport(0, 0, width, height);
//
//        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//        glEnable(GL_CULL_FACE);
//
//        const int COORD = glGetAttribLocation(Dragon3DProgram, "a_coord");
//        std::cout << COORD << std::endl;
//        glEnableVertexAttribArray(COORD);
//        glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glBufferData(GL_ARRAY_BUFFER, objLoader.data->vertices.size() * sizeof(glm::vec3), &objLoader.data->vertices[0],GL_STATIC_DRAW);

//        int size;
//        glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);

        glDrawElements(GL_TRIANGLES, objLoader.data->vertices.size(), GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    Terminate();
    glfwTerminate();
    return 0;
}
