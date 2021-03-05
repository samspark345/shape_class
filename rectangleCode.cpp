#include<iostream>
#include<string>
using namespace std;


class Point2D{
private:
    float x; float y;
public:
    Point2D (){}
    Point2D(Point2D &other){
        x=other.x;
        y=other.y;
    }
    Point2D(float xCord, float yCord){
        x = xCord;
        y = yCord;
    }
    void setX(float xCord){
        x = xCord;
    }
    void setY(float yCord){
        y = yCord;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }

};

class Rectangle2D{
private:
    Point2D bottomLeft;
    Point2D topRight;

public:
    Rectangle2D( Point2D bl,  Point2D tr){
        bottomLeft = bl;
        topRight = tr;
    }

    Rectangle2D(Rectangle2D &other){
        bottomLeft = other.bottomLeft;
        topRight = other.topRight;
    }
    bool contains(Point2D point){
        return (topRight.getY()>=point.getY() && bottomLeft.getY()<=point.getY() && topRight.getX() >=point.getX() && bottomLeft.getX() <= point.getX());
    }
    bool intersect(Rectangle2D other){
        return(contains(other.topRight)&& contains(other.bottomLeft));
    }
};

int main(){
    Point2D first(0,0);
    Point2D second(6, 5);
    Point2D third(7,6);
    Point2D fourth(12,10);
    Point2D fifth(2,5);
    Rectangle2D firstRect(first ,second);
    Rectangle2D secondRect(first ,second);
    Rectangle2D thirdRect(third ,fourth);
    Rectangle2D fourthRect(thirdRect);
    cout<<"(so if it intersects it is 1 else 0) "<<firstRect.intersect(secondRect)<<endl;
    cout<<"(so if it intersects it is 1 else 0) "<<secondRect.intersect(thirdRect)<<endl;
    cout<<"(so if it contains it is 1 else 0) "<<firstRect.contains(fifth)<<endl;
    cout<<"(so if it contains it is 1 else 0) "<<firstRect.contains(third)<<endl;
    cout<<"(so if it intersects it is 1 else 0) "<<fourthRect.intersect(thirdRect)<<endl;
}
