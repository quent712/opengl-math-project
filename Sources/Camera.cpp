//
// Created by berthelot Mickael on 05/05/2021.
//

#include "../Headers/Camera.h"

Camera::Camera (const std::vector<float> &position,
                const float &fov,
                const float &zNear,
                const float &zFar,
                const float &width,
                const float &height) {
    this->positionVector = position;
    this->setFov(fov);
    this->setZFar(zFar);
    this->setZNear(zNear);
    this->setAspect(width, height);
};

float Camera::getX() const {
    return this->positionVector[0];
};

void Camera::setX(float x) {
    this->positionVector[0] = x;
};

float Camera::getY() const {
    return this->positionVector[1];
};

void Camera::setY(float y) {
    this->positionVector[1] = y;
};

float Camera::getZ() const {
    return this->positionVector[2];
};

void Camera::setZ(float z) {
    this->positionVector[2] = z;
};

float Camera::getAspect() const {
    return this->aspect;
};

void Camera::setAspect(float width, float height) {
    this->aspect = (float)(width/height);
};

float Camera::getFov() const {
    return this->fov;
};

void Camera::setFov(const float fov) {
    this->fov = fov;
    this->updateRadianFov();
    this->updateCot();
};

float Camera::getZFar() const {
    return this->zFar;
};

void Camera::setZFar(float zFar) {
    this->zFar = zFar;
};

float Camera::getZNear() const {
    return this->zNear;
};

void Camera::setZNear(float zNear) {
    this->zNear = zNear;
};

float Camera::getCot() const {
    return this->cot;
};

void Camera::updateRadianFov() {
    this->radianFov = this->fov * (float)(M_PI /180.0);
};

void Camera::updateCot() {
    this->cot = 1.0f / tanf(this->radianFov / 2.0f);
};
