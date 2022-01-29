#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>
#
int main() {

    /*
    * 0作业要求：
    *   给定一个点 P=(2,1), 将该点绕原点先逆时针旋转 45◦，再平移 (1,2), 计算出
    *   变换后点的坐标（要求用齐次坐标进行计算）。
    */
    
    Eigen::Vector3d vec(2,1,1),ans;
    Eigen::Matrix3d Mat;
    Mat << 0.707, -0.707, 0,
           0.707, 0.707 , 0,
           0,     0,      1;
    ans = Mat * vec;
    std::cout << "向量:" <<std::endl<< vec << std::endl;
    std::cout << "旋转矩阵：" <<std::endl<< Mat << std::endl;
    std::cout << "旋转后点坐标为：" << std::endl<< ans << std::endl;


    Eigen::Matrix3d Mat2;
    Mat2 << 1, 0, 1,
            0, 1, 2,
            0, 0, 1;
    ans = Mat2*ans;
    std::cout << "平移矩阵为：" << std::endl << Mat2<<std::endl;
    std::cout << "平移后点坐标为：" << std::endl << ans << std::endl;

    return 0;
}