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

//Addition de Quaternion
void Quaternion::operator+(const Quaternion *quat) {
this.x+= quat.x;
this.y+= quat.y;
this.z+= quat.z;
this.w+= quat.w;
}

void Quaternion::normalization() {          //normaliser
// Don't normalize if we don't have to 
float mag2 = w * w + x * x + y * y + z * z; 
if (fabs(mag2 - 1.0f) > 0.00001f)  // fabs pour avoir valeur absolue , 0.00001f est la tolérence 
{ float mag = sqrt(mag2); //pour racine carré de mag2
this.w /= mag; this.x /= mag; this.y /= mag; this.z /= mag; } }

Quaternion Quaternion::Conjugation() {  //conjugaison
 return Quaternion(-this.x, -this.y, -this.z, this.w); 
 }
 
 Quaternion Quaternion::operator* (const Quaternion *rq) const {  //Multiplication
 return Quaternion(w * rq.x + x * rq.w + y * rq.z - z * rq.y, w * rq.y + y * rq.w + z * rq.x - x * rq.z, 
 w * rq.z + z * rq.w + x * rq.y - y * rq.x, w * rq.w - x * rq.x - y * rq.y - z * rq.z); }
 

 //Multiplier un quaternion q avec un vecteur v applique la q-rotation à v Vector3 
 //Quaternion::operator* (const Vector3 *vec) { Vector3 vn(vec); 
 
 //vn.normalisation();
 
 //Quaternion vecQuat, resQuat; vecQuat.x = vn.x; vecQuat.y = vn.y; vecQuat.z = vn.z; vecQuat.w = 0.0f;
 
 //resQuat = vecQuat * getConjugate(); resQuat = *this * resQuat;
 
// this.x = resQuat.x, this.y = resQuat.y, this.z= resQuat.z; } 
 

 // Convert Quaternion to Matrix Matrix4 Quaternion::
 glm::mat4 glm::mat4::QuaterniontoMatrix(){
 float x2 = x * x; 
 float y2 = y * y; 
 float z2 = z * z; 
 float xy = x * y; 
 float xz = x * z; 
 float yz = y * z; 
 float wx = w * x; 
 float wy = w * y; 
 float wz = w * z;
 return glm::mat4( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f, 2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f, 2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0 f, 0,0f, 0,0f, 0,0f, 1,0f) }
 }
 
//Produit squalaire
float float::produitsqualaire(const glm::mat4 *mat) {
Quaternion sq = MatrixtaQuaternion(mat); 
return (this.x * sq.x + this.y * sq.y + this.z * sq.z + this.w * sq.w);
}

//Matrix to a Quaternion
Quaternion MatrixtoQuaternion(const glm::mat4 *src){	const float trace = 1.0f + src->m00 + src->m11 + src->m22;	
if (trace > 0.00001f)	{		
    const float s = sqrt(trace) * 2;		
    
    return Quaternion((src->m21 - src->m12) / s,(src->m02 - src->m20) / s,(src->m10 - src->m01) / s,s / 4);	}	
    
else if (src->m00 > src->m11 && src->m00 > src->m22)	{
    const float s = sqrt(1.0f + src->m00 - src->m11 - src->m22) * 2;
    return Quaternion(			s / 4,			(src->m10 + src->m01) / s,
    (src->m02 + src->m20) / s,(src->m21 - src->m12) / s);	}	
    
else if (src->m11 > src->m22)	
{
    const float s = sqrt(1.0f + src->m11 - src->m00 - src->m22) * 2;
    return Quaternion(	(src->m10 + src->m01) / s,s / 4,(src->m21 + src->m12) / s,	(src->m02 - src->m20) / s);	}	

else	{	const float s = sqrt(1.0f + src->m22 - src->m00 - src->m11) * 2;		
return Quaternion(	(src->m02 + src->m20) / s,	(src->m21 + src->m12) / s,	s / 4,	(src->m10 - src->m01) / s);	}


}