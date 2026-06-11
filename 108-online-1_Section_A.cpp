#include<iostream>
#include<cmath>
using namespace std;


class Point
{
  private:
  double x, y;

  public:
  Point()
    {
      this->x=0;
      this->y=0;
    }
  

  Point(double x, double y)
    {
      this->x=x;
      this->y=y;
    }  

  void setCoordinates(double x, double y)
  {
    this->x=x;
    this->y=y;
  }  

  Point  translate(double  dx,  double  dy)
  {
    Point new_point;
    new_point.x=this->x+dx;
    new_point.y=this->y+dy;
    return new_point;
  }

  double  cross(const  Point&  other)
  {
    return this->x*other.y-this->y*other.x;
  }

  double  getDistance(const  Point&  other)
  {
    return sqrt(pow(this->x-other.x, 2)+pow(this->y-other.y, 2));
  }
  
  void display()
  {
    cout<<"("<<this->x<<","<<this->y<<")"<<endl;
  }
};



class Polygon
{
  private:
  Point* vertices;
  int numVertices;

  public:
  Polygon()
  {
    vertices=new Point[10];
    numVertices=10;
  }

  Polygon(Point* vertices, int n)
  {
    numVertices=n;
    this->vertices=new Point[n];
    for(int i=0; i<n; i++)
    {
      this->vertices[i]=vertices[i];
    }
  }

  Polygon(const Polygon& other)
  {
    this->numVertices=other.numVertices;
    this->vertices=new Point[this->numVertices];
    for(int i=0; i<this->numVertices; i++)
    {
      this->vertices[i]=other.vertices[i];
    }
  }

  ~Polygon()
  {
    delete[] this->vertices;
  }

  Polygon  translate(double  dx,  double  dy)
  {
    Polygon new_polygon;
    new_polygon.numVertices=this->numVertices;
    new_polygon.vertices=new Point[new_polygon.numVertices];
    for(int i=0; i<new_polygon.numVertices; i++)
    {
      new_polygon.vertices[i]=this->vertices[i].translate(dx, dy);
    }
    return new_polygon;
  }

  void display()
  {
    cout<<"No. of vertices: "<<this->numVertices<<endl;
    for(int i=0; i<this->numVertices; i++)
    {
      this->vertices[i].display();
    }
    cout<<"Perimeter: ";
    cout<<this->getPerimeter();
    cout<<", Area: ";
    cout<<this->getArea();
    cout<<endl;
  }

  void addVertex(Point p)
  {
    int i=0;
    Polygon new_polygon(*this);
    this->numVertices=this->numVertices+1;
    this->vertices=new Point[this->numVertices];
    for(i=0; i<new_polygon.numVertices; i++)
    {
      this->vertices[i]=new_polygon.vertices[i];
    }
    this->vertices[i]=p;
  }

  double getArea()
  {
    int i=0;
    double area=0.0;
    for(i=0; i<this->numVertices-1; i++)
    {
      area+=this->vertices[i].cross(this->vertices[i+1]);
    }
    area+=this->vertices[i].cross(this->vertices[0]);
    return area*0.5;
  }

  double getPerimeter()
  {
    double perimeter=0.0;
    for(int i=0; i<this->numVertices-1; i++)
    {
      perimeter+=this->vertices[i].getDistance(this->vertices[i+1]);
    }
    perimeter+=this->vertices[0].getDistance(this->vertices[this->numVertices-1]);
    return perimeter;
  }
};



int main() { 
  Point p1(0, 0); 
  Point p2(4, 0); 
  Point p3(4, 3); 
  Point p4(0, 3); 
  Point vertices[] = {p1, p2, p3}; 
  Polygon triangle(vertices, 3); 
  Polygon translatedTriangle = triangle.translate(2, 1); 
  cout << "Original Triangle:\n"; 
  triangle.display(); 
  cout << "\nTranslated Triangle:\n"; 
  translatedTriangle.display(); 
  Polygon square = triangle; 
  square.addVertex(p4); 
  cout << "\nSquare:\n"; 
  square.display(); 
  return 0; 
  }