//
// Created by berthelot Mickael on 05/05/2021.
//

#ifndef OPENGL_PROJECT_CAMERA_H
#define OPENGL_PROJECT_CAMERA_H

#include <cstdio>
#include <cmath>
#include <vector>

class Camera {

public:
    Camera(const std::vector<float> &position,
           const float &fov,
           const float &zNear,
           const float &zFar,
           const float &width,
           const float &height);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getZ() const;
    void setZ(float z);

    float getAspect() const;
    void setAspect(float width, float height);

    float getFov() const;
    void setFov(const float fov);

    float getZNear() const;
    void setZNear(float zNear);

    float getZFar() const;
    void setZFar(float zFar);

    float getCot() const;

private:
    void updateRadianFov();
    void updateCot();

    std::vector<float> positionVector;
    float fov{};
    float radianFov{};
    float cot{};
    float aspect{};
    float zNear{};
    float zFar{};

};


#endif //OPENGL_PROJECT_CAMERA_H
