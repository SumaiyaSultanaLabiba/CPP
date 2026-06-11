#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Circle class definition
class Circle{
    double x, y;         // Coordinates of the center of the circle
    double radius;       // Radius of the circle
    char* name;          // Name of the circle
    char* color;         // Color of the circle

public:
    // Default constructor to initialize a circle with default values
    Circle()
    {
        x=0; y=0; radius=10;
        name=new char[10];
        color=new char[10];
        strcpy(name,"Default");
        strcpy(color, "White");
    }



    // Constructor with parameters for a circle's name, coordinates, and radius
    Circle(const char* name, double x, double y, double r)
    {
        this->x=x; this->y=y;
        this->radius=r;
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->color=new char[10];
        strcpy(this->color, "White");
    }





    // Create a new circle from an existing one
    Circle(const Circle &c)
    {
        this->name=new char[strlen(c.name)+1];
        strcpy(this->name, c.name);
        this->x=c.x;
        this->y=c.y;
        this->radius=c.radius;
        this->color=new char[strlen(c.color)+1];
        strcpy(this->color, c.color);
    }



    // Method to calculate and return the area of the circle
    double area()
    {
        return 3.1416*this->radius*this->radius;
    }



    // Method to calculate and return the circumference of the circle
    double circumference()
    {
        return 3.1416*this->radius*2;
    }



    // Method to check if a point (x, y) is inside the circle
    void contains(double x, double y)
    {
        double center_point=sqrt((this->x-x)*(this->x-x)+(this->y-y)*(this->y-y));
        if(center_point<this->radius)
        {
            cout<<"Point ("<<x<<", "<<y<<") is inside the Circle "<<this->name<<endl;
        }
        else if(center_point>this->radius) 
        {
            cout<<"Point ("<<x<<", "<<y<<") is outside the Circle "<<this->name<<endl;
        }
        else
        {
            cout<<"Point ("<<x<<", "<<y<<") is on the Circle "<<this->name<<endl;
        }
    }



    // Method to check if another circle is inside, intersects, or outside this circle
    void contains(Circle c)
    {
       double center_center=sqrt((this->x-c.x)*(this->x-c.x)+(this->y-c.y)*(this->y-c.y));
       if(center_center>=this->radius+c.radius) {cout<<"Circle "<<c.name<<" is outside the Circle "<<this->name<<endl;}
       else if(center_center<=this->radius-c.radius) {cout<<"Circle "<<c.name<<" is inside the Circle "<<this->name<<endl;}
       else {cout<<"Circle "<<c.name<<" intersects the Circle "<<this->name<<endl;}
    }



    // Method to translate the circle's position by a distance (dx, dy)
    void translate(double dx, double dy)
    {
        this->x+=dx; 
        this->y+=dy;
    }



    // Method to translate the circle in a given direction (up, down, left, right)
    void translate(string dir, double dist)
    {
       if(dir=="up") {this->y+=dist;}
       if(dir=="down") {this->y-=dist;}
       if(dir=="left") {this->x-=dist;}
       if(dir=="right") {this->x+=dist;}
    }




    // Method to scale the circle by a given factor
    void scale(double factor)
    {
        this->radius*=factor;
    }



    // Method to display circle properties (name, center, radius, area, cirumference, color.)
    void display()
    {
        cout<<"Circle Name: "<<this->name<<endl;
        cout<<"Center: ("<<this->x<<", "<<this->y<<")"<<endl;
        cout<<"Radius: "<<this->radius<<endl;
        cout<<"Area: "<<3.1416*this->radius*this->radius<<endl;
        cout<<"Circumference: "<<3.1416*this->radius*2<<endl;
        cout<<"Color: "<<this->color<<endl;
    }



    // Setter method for the name of the circle
    void setName(const char* name)
    {
        delete[] this->name;
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
    }



    // Setter method for the color of the circle
    void setColor(const char* color)
    {
        delete[] this->color;
        this->color=new char[strlen(color)+1];
        strcpy(this->color, color);
    }



    // Getter method for the circle's name
    char* getName()
    {
        return this->name;
    }



    // Getter method for the circle's color
    char* getColor()
    {
        return this->color;
    }



    // Destructor to clean up dynamically allocated memory
    ~Circle()
    {
        delete[] name;
        delete[] color;
    }
};

// Main function to test the Circle class
int main() {
    Circle c1("C1", 0, 0, 5);  // Create a circle with name C1 at (0,0) with radius 5
    Circle c2("C2", 6, 4, 1);  
    Circle c3("C3", 2, 2, 3);  
    Circle c4("C4", 1, 2, 2);  
    c1.setColor("Red");  // Set color of circle C1 to Red
    c2.setColor("Blue"); 

    c1.display();  // Display properties of circle C1
    cout << endl;
    c2.display();  
    cout << endl;

    // Test 
    c1.contains(3, 5);  // Point (3, 5) should be outside circle C1
    c1.contains(2, 2);  // Point (2, 2) should be inside circle C1
    c1.contains(c2);    // Check if circle C2 is inside, intersects, or outside circle C1
    c1.contains(c3);    
    c1.contains(c4);    

    // Translate circle C1 by (2, 3)
    c1.translate(2, 3);
    c1.display();
    cout << endl;

    // Translate circle C1 upwards by 2 units
    c1.translate("up", 2);
    c1.display();
    cout << endl;

    // Scale circle C1 by a factor of 2
    c1.scale(2);
    c1.display();
    return 0;
}