
//二维向量库
//由 pzy 编写
#include <cmath>
#include <string>
#include <vector>

using namespace std;
const double eps_of_vector = 1e-8;
#define EOV eps_of_vector
namespace Vector2 // 平面向量
{

    struct vector2 // 从原点出发的向量
    {
        double x, y;
        vector2() : x(0.000), y(0.0000) {}
        vector2(double a, double b) : x(a), y(b) {}

        friend bool operator==(const vector2 &a, const vector2 &b)
        {
            if (abs(a.x - b.x) < EOV && abs(a.y - b.y) < EOV)
            {
                return 1;
            }
            return 0;
        }
        friend bool operator!=(const vector2 &a, const vector2 &b)
        {
            if (abs(a.x - b.x) < EOV && abs(a.y - b.y) < EOV)
            {
                return 0;
            }
            return 1;
        }
        // 向量加减
        friend vector2 operator+(const vector2 &a, const vector2 &b)
        {
            return (vector2){a.x + b.x, a.y + b.y};
        }
        friend void operator+=(vector2 &a, const vector2 &b)
        {
            a = (vector2){a.x + b.x, a.y + b.y};
        }
        friend vector2 operator-(const vector2 &a, const vector2 &b)
        {
            return (vector2){a.x + (-b.x), a.y + (-b.y)};
        }
        friend void operator-=(vector2 &a, const vector2 &b)
        {
            a = (vector2){a.x + (-b.x), a.y + (-b.y)};
        }

        // 向量数乘
        friend vector2 operator*(const vector2 &a, const double &b)
        {
            return (vector2){a.x * b, a.y * b};
        }
        friend vector2 operator*(const double &a, const vector2 &b)
        {
            return (vector2){b.x * a, b.y * a};
        }
        friend void operator*=(vector2 &a, const double &b)
        {
            a = (vector2){a.x * b, a.y * b};
        }
        // 向量点乘
        friend double operator^(const vector2 &a, const vector2 &b)
        {
            return double(a.x * b.x + a.y * b.y);
        }
        double module() //模长
        {
            return sqrt(this->x * this->x + this->y * this->y);
        }
        double norm() //同上
        {
            return this->module();
        }

        //----------------------------------------------------------
        string to_string()
        {
            return "(" + std::to_string(this->x) + ',' + std::to_string(this->y) + ')';
        }
    };
    struct vector2_p // 平面中移动的向量
    {
        double ex, ey;
        double sx, sy;
    };
    struct vector2_i // 从原点出发的向量(坐标为整数)
    {
        int x, y;
        vector2_i() : x(0), y(0) {}
        vector2_i(int a, int b) : x(a), y(b) {}

        friend bool operator==(const vector2_i &a, const vector2_i &b)
        {

            return a.x == b.x && a.y == b.y;
        }
        friend bool operator!=(const vector2_i &a, const vector2_i &b)
        {
            return !(a == b);
        }
        // 向量加减
        friend vector2_i operator+(const vector2_i &a, const vector2_i &b)
        {
            return (vector2_i){a.x + b.x, a.y + b.y};
        }
        friend void operator+=(vector2_i &a, const vector2_i &b)
        {
            a = (vector2_i){a.x + b.x, a.y + b.y};
        }
        friend vector2_i operator-(const vector2_i &a, const vector2_i &b)
        {
            return (vector2_i){a.x + (-b.x), a.y + (-b.y)};
        }
        friend void operator-=(vector2_i &a, const vector2_i &b)
        {
            a = (vector2_i){a.x + (-b.x), a.y + (-b.y)};
        }

        // 向量数乘
        friend vector2_i operator*(const vector2_i &a, const int &b)
        {
            return (vector2_i){a.x * b, a.y * b};
        }
        friend vector2_i operator*(const int &a, const vector2_i &b)
        {
            return (vector2_i){b.x * a, b.y * a};
        }
        friend void operator*=(vector2_i &a, const int &b)
        {
            a = (vector2_i){a.x * b, a.y * b};
        }
        // 向量点乘
        friend double operator^(const vector2_i &a, const vector2_i &b)
        {
            return double(a.x * b.x + a.y * b.y);
        }
        double module() //模长
        {
            return sqrt(this->x * this->x + this->y * this->y);
        }
        double norm() //同上
        {
            return this->module();
        }

        //----------------------------------------------------------
        string to_string()
        {
            return "(" + std::to_string(this->x) + ',' + std::to_string(this->y) + ')';
        }
    };
    const vector2_i X_i = {1, 0};
    const vector2_i Y_i = {0, 1};
    //两个基向量
    const vector2 X_ = {1.00000000000, 0.000000000000};
    const vector2 Y_ = {0.00000000000, 1.000000000000};
    // 45°
    const vector2 _45 = {0.70710678118654752440084436210485, 0.70710678118654752440084436210485};

}
namespace Vector2_ext
{

}
//三维向量库
//由 pzy 编写
namespace Vector3 //三维向量
{

    struct vector3 // 从原点出发的向量
    {
        double x, y, z;
        vector3() : x(0.000), y(0.0000), z(0.0000) {}
        vector3(double a, double b, double c) : x(a), y(b), z(c) {}
        friend bool operator==(const vector3 &a, const vector3 &b)
        {
            if (abs(a.x - b.x) < EOV && abs(a.y - b.y) < EOV && abs(a.z - b.z) < EOV)
            {
                return 1;
            }
            return 0;
        }
        friend bool operator!=(const vector3 &a, const vector3 &b)
        {
            if (abs(a.x - b.x) < EOV && abs(a.y - b.y) < EOV && abs(a.z - b.z) < EOV)
            {
                return 0;
            }
            return 1;
        }
        // 向量加减
        friend vector3 operator+(const vector3 &a, const vector3 &b)
        {
            return (vector3){a.x + b.x, a.y + b.y, a.z + b.z};
        }
        friend void operator+=(vector3 &a, const vector3 &b)
        {
            a = (vector3){a.x + b.x, a.y + b.y, a.z + b.z};
        }
        friend vector3 operator-(const vector3 &a, const vector3 &b)
        {
            return (vector3){a.x + (-b.x), a.y + (-b.y), a.z + (-b.z)};
        }
        friend void operator-=(vector3 &a, const vector3 &b)
        {
            a = (vector3){a.x + (-b.x), a.y + (-b.y), a.z + (-b.z)};
        }

        // 向量数乘
        friend vector3 operator*(const vector3 &a, const double &b)
        {
            return (vector3){a.x * b, a.y * b, a.z * b};
        }
        friend vector3 operator*(const double &a, const vector3 &b)
        {
            return (vector3){b.x * a, b.y * a, b.z * a};
        }
        friend void operator*=(vector3 &a, const double &b)
        {
            a = (vector3){a.x * b, a.y * b, a.z * b};
        }
        // 向量点乘
        friend double operator^(const vector3 &a, const vector3 &b)
        {
            return double(a.x * b.x + a.y * b.y + a.z * b.z);
        }
        double module() //模长
        {
            return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        }
        double norm() //同上
        {
            return this->module();
        }
        string to_string()
        {
            return "(" + std::to_string(this->x) + ',' + std::to_string(this->y) + "," + std::to_string(this->z) + ')';
        }
    };
    struct vector3_p //平面中移动的向量
    {
        double ex, ey, ez;
        double sx, sy, sz;
    };
    const vector3 X_ = {1.00000, 0, 0};
    const vector3 Y_ = {0, 1.0000, 0};
    const vector3 Z_ = {0, 0, 1.000000};
    vector3 Cross(vector3 a, vector3 b)
    {
        return vector3(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x);
    }

}
//多维向量库
//由 pzy 编写

// High-dimensional vector
namespace VectorHd // 高维向量
{
    struct vector_hd // 从原点出发的向量
    {
        // double x, y;
        vector<double> c;
        // 向量加减
        friend vector_hd operator+(const vector_hd &a, const vector_hd &b)
        {
        }
        friend void operator+=(vector_hd &a, const vector_hd &b)
        {
        }
        friend vector_hd operator-(const vector_hd &a, const vector_hd &b)
        {
        }
        friend void operator-=(vector_hd &a, const vector_hd &b)
        {
        }

        // 向量数乘
        friend vector_hd operator*(const vector_hd &a, const double &b)
        {
        }
        friend vector_hd operator*(const double &a, const vector_hd &b)
        {
        }
        friend void operator*=(vector_hd &a, const double &b)
        {
        }
        // 向量点乘
        friend double operator^(const vector_hd &a, const vector_hd &b)
        {
        }
    };

}

namespace Vector_basic
{
    using namespace Vector2;
    // using namespace Vector2_ext;
    using namespace Vector3;
}
namespace Vector_ext
{
    using namespace Vector_basic;
    using namespace Vector2_ext;
    // using namespace Vector3;
} // namespace Vector_ext
namespace Vector_all
{
    using namespace Vector2;
    using namespace Vector3;
    using namespace VectorHd;

}
