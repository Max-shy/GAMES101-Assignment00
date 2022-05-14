# GAMES101-Assignment0
对给定应该坐标点(2,1,1)，求解逆时针旋转45度再平移(1,2)后的坐标

Assignment 0 is about the construction of the operating environment and the exercise of matrix operation. In this assignment, I need to rotate and translate a point P=(2,1) using homogeneous coordinates.

I add an extra dimension called homogeneous coordinates. Homogeneous coordinates not only clean up the code for transformations, but this scheme also makes it obvious how to compose two affine transformations: simply multiply the matrices.

In the course, there are two representations of the homogeneous coordinates of 2D points.

[x,y,0] is a displacement or direction vector, and [x,y,1] is a location or point.  

So we define the P = (2,1,1).

Then I use the rotation matrix to rotate it 45°  about the origin.
Because I'm using homogeneous coordinates, and w = 1, I can represent any number of 2D shears, 2D rotations, and 2D translations as one composite 3D matrix.


```cpp
int main() {
    /*
    * 0作业要求：
    *   给定一个点 P=(2,1), 将该点绕原点先逆时针旋转 45◦，再平移 (1,2), 计算出
    *   变换后点的坐标（要求用齐次坐标进行计算）。
    */
    Eigen::Vector3d P(2.0f,1.0f,1.0f),ans;
    Eigen::Matrix3d rotate;
    Eigen::Matrix3d trans;
    double phi = 45.0 / 180.0 * PI;
    
    //rotation matrix 
    rotate << cos(phi), -sin(phi), 0,
              sin(phi), cos(phi), 0,
              0,     0,      1;
    
	//translation matrix
    trans << 1, 0, 1,
             0, 1, 2,
             0, 0, 1;
    
    ans = trans * rotate * P;
    std::cout << ans << std::endl;
    return 0;
}
```

Assignment 0 uses a transformation matrix to perform the basic model transformation on 2D points. The model transformation in 3D space is similar to that in 2D, but the rotation transformation is more complex. 


Rotation around different axes requires different rotation matrices but combining multiple rotation matrices results in **Gimbal Lock**. I found out the cause of Gimbal Lock by searching for information.[[bonus_gimbal_lock.pdf (krasjet.github.io)](https://krasjet.github.io/quaternion/bonus_gimbal_lock.pdf)]

Rodrigues Rotation formulas can greatly avoid Gimbal locks, but they can't completely solve the problem. To truly prevent Gimbal locks we have to represent rotations using quaternions, that are not only safer but also more computationally friendly. Then I learned something about quaternions and 3D rotation in this article.[[quaternion.pdf (krasjet.github.io)](https://krasjet.github.io/quaternion/quaternion.pdf)]

