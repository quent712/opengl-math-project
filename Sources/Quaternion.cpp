//
// Created by berthelot Mickael on 08/05/2021.
//

#include "../Headers/Quaternion.h"

Quaternion::Quaternion(const std::vector<float> &RotationAxis,
                       const float &RotationAngle ) {
                       
x = RotationAxis.x * sin(RotationAngle / 2)
y = RotationAxis.y * sin(RotationAngle / 2)
z = RotationAxis.z * sin(RotationAngle / 2)
w = cos(RotationAngle / 2)
};


void Quaternion::normalise() {          //normaliser
// Don't normalize if we don't have to 
float mag2 = w * w + x * x + y * y + z * z; 
if (fabs(mag2 - 1.0f) > 0.00001f)  // fabs pour avoir valeur absolue , 0.00001f est la tolérence 
{ float mag = sqrt(mag2); //pour racine carré de mag2
this.w /= mag; this.x /= mag; this.y /= mag; this.z /= mag; } }

Quaternion Quaternion::getConjugate() {  //conjugaison
 return Quaternion(this.-this.x, -this.y, -this.z, this.w); 
 }
 
 Quaternion Quaternion::operator* (const Quaternion &rq) const {  //Multiplication
 return Quaternion(w * rq.x + x * rq.w + y * rq.z - z * rq.y, w * rq.y + y * rq.w + z * rq.x - x * rq.z, 
 w * rq.z + z * rq.w + x * rq.y - y * rq.x, w * rq.w - x * rq.x - y * rq.y - z * rq.z); }
 
 
 // Multiplier un quaternion q avec un vecteur v applique la q-rotation à v Vector3 
 Quaternion::operator* (const Vector3 &vec) const { Vector3 vn(vec); vn.normalise();
 
 Quaternion vecQuat, resQuat; vecQuat.x = vn.x; vecQuat.y = vn.y; vecQuat.z = vn.z; vecQuat.w = 0.0f;
 
 resQuat = vecQuat * getConjugate(); resQuat = *this * resQuat;
 
 return (Vector3(resQuat.x, resQuat.y, resQuat.z)); }
 
 
 // Convert to Matrix Matrix4 Quaternion::
 Matrix4 Matrix4::ConverttoMatrix(){
 float x2 = x * x; float y2 = y * y; float z2 = z * z; float xy = x * y; float xz = x * z; float yz = y * z; float wx = w * x; float wy = w * y; float wz = w * z;
 return glm::mat4( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f, 2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f, 2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0 f, 0,0f, 0,0f, 0,0f, 1,0f) }
 }
 
