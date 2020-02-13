#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
#include <memory>

class Vector3f {
    public:
        float x{0};
        float y{0};
        float z{0};
    Vector3f() {
    }
    Vector3f (float X, float Y, float Z) {
        x = X;
        y = Y;
        z = Z;
    }
    Vector3f (const Vector3f &orig){
        x = orig.x;
        y = orig.y;
        z = orig.z;
    }

};
bool operator==(const Vector3f a,const Vector3f b){
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
bool operator!=(const Vector3f a,const Vector3f b){
    return (a.x != b.x) && (a.y != b.y) && (a.z != b.z);
}
Vector3f operator+(const Vector3f a,const Vector3f b){
    return Vector3f{a.x + b.x, a.y + b.y,a.z + b.z};
}
Vector3f operator-(const Vector3f a,const Vector3f b){
    return Vector3f{a.x - b.x, a.y - b.y,a.z - b.z};
}
Vector3f operator*(const Vector3f a,const Vector3f b){
    return Vector3f{a.x * b.x, a.y * b.y,a.z * b.z};
}
Vector3f operatorx(const Vector3f a,const Vector3f b){
    return Vector3f{a.x * b.x, a.y * b.y,a.z * b.z};
}
TEST_CASE("Vector Studd", "[vector]"){
    Vector3f zero{0.0f,0.0f,0.0f};
    Vector3f one {1.0f,1.0f,1.0f};
    Vector3f two {2.0f,2.0f,2.0f};
    Vector3f three {3.0f,3.0f,3.0f};

    auto one_copy = one;
    REQUIRE(zero == zero);
    REQUIRE(one_copy == one);
    REQUIRE(zero != one);
    // REQUIRE(zero == one);
    REQUIRE(two + one == three);
    REQUIRE(three - two == one);
    REQUIRE(one * two == two);
    REQUIRE(one + two == two);

}