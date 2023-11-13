// #include <iostream>
// #include <cmath>
// #include <string>
// const float PI = acos(-1);
// using namespace std;

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const float PI = acos(-1);

class Point
{
protected:
    float r;

public:
    Point(float _r) : r(_r) {}

    virtual void increase(float _delta)
    {
        r *= _delta;
    }
    virtual Point &operator*(float _delta)
    {
        r *= _delta;
        return *this;
    }
    friend ostream &operator<<(ostream &stream, const Point &object)
    {
        stream << "R =" << object.r;
        return stream;
    }
    friend istream &operator>>(istream &stream, Point &object)
    {
        stream >> object.r;
        return stream;
    }
    float get_r()
    {
        return r;
    }
    Point operator=(const Point &object)
    {
        return Point(object.r);
    }
};

class Circle : public Point
{
public:
    Circle(float r) : Point(r) {}

    virtual float area()
    {
        return PI * r * r;
    }

    virtual void increase(float _delta) override
    {
        Point::increase(_delta);
    }

    virtual Circle &operator*(float _delta) override
    {
        Point x = Point::operator*(_delta);
        r = x.get_r();
        return *this;
    }

    Circle operator=(const Circle &object)
    {
        return Circle(object.r);
    }
    // friend ostream &operator<<(ostream &stream, const Circle &object)
    // {
    //     stream << "R = " << object.r;
    //     return stream;
    // }
};

class Ring : public Circle
{
private:
    float rin;

public:
    Ring(float _r, float _rin) : Circle(_r), rin(_rin) {}

    virtual float area() override
    {
        return Circle::area() - 3.14159 * rin * rin;
    }

    virtual void increase(float _delta) override
    {
        Circle::increase(_delta);
        rin *= _delta;
    }
    virtual Ring &operator*(float _delta) override
    {
        Circle x = Circle::operator*(_delta);
        r = x.get_r();
        rin *= _delta;
        return *this;
    }

    friend ostream &operator<<(ostream &stream, const Ring &object)
    {
        stream << "R =" << object.r << ", rin =" << object.rin;
        return stream;
    }

    friend istream &operator>>(istream &stream, Ring &object)
    {
        stream >> object.r >> object.rin;
        return stream;
    }

    Ring operator=(const Ring &object)
    {
        return Ring(object.r, object.rin);
    }

    float get_rin()
    {
        return rin;
    }
};

// // точка
// class Circumference
// {
// protected:
//     float r;

// public:
//     Circumference(float _r = 1)
//     {
//         r = _r;
//     }
//     virtual float Square() = 0;
//     virtual void increase(const float &_delta)
//     {
//         r *= _delta;
//     }
//     virtual Circumference &operator+(const float &delta)
//     {
//         r += delta;
//         return *this;
//     }
// };

// // круг
// class Circle : Circumference
// {
// protected:
//     float r;

// public:
//     Circle(float _r = 1):Circumference(_r){}
//     Circle(const Circle &object):Circumference(object.r){}

//      float Square() const
//     {
//         return PI * r * r;
//     }
//     virtual void increase(const float &_delta)
//     {
//         r *= _delta;
//     }
//     virtual Circle &operator+(const float &delta)
//     {
//         r += delta;
//         return *this;
//     }

//     friend ostream &operator<<(ostream &stream, const Circle &object)
//     {
//         stream << "R = " + to_string(object.r) + ", Square = " + to_string(object.Square()) + "\n\n";
//         return stream;
//     }
//     friend istream &operator>>(istream &stream, Circle &object)
//     {
//         stream >> object.r;
//         return stream;
//     }
//     Circle operator=(const Circle &object)
//     {
//         return Circle(object.r);
//     }
// };

// class Ring : public Circle
// {
//     float rin;

// public:
//     // Внешний, потом внутренний
//     Ring(const float &_r, const float &_rin) : Circle(_r), rin(_rin) {}

//     float Square() const
//     {
//         return Circle::Square() - PI * rin * rin;
//     }
//     void increase(const float &_delta = 1)
//     {
//         Circle::increase(_delta);
//         rin *= _delta;
//     }

//     Ring &operator+(const float &delta)
//     {
//         // r += delta;
//         *this = *this + 5; // Circle::operator+
//         rin += delta;
//         return *this;
//     }
//     friend ostream &operator<<(ostream &stream, const Ring &object)
//     {
//         stream << "R = " + to_string(object.r) + ", r = " + to_string(object.rin) + ", Square = " + to_string(object.Square()) + "\n\n";
//         return stream;
//     }
//     friend istream &operator>>(istream &stream, Ring &object)
//     {
//         // Внешний, потом внутренний радиус
//         stream >> object.r >> object.rin;
//         return stream;
//     }
//     Ring operator=(const Ring &object)
//     {
//         return Ring(object.r, object.rin);
//     }
// };
