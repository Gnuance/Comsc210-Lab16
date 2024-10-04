// Lab 16: Creates multiple color objects consisting of RGB values and outputs those object values to console.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

// Declare color class to store RGB values
class Color
{
private:
    int r;
    int g;
    int b;

public:
    Color();
    Color(int, int, int);
    void setR(int);
    void setG(int);
    void setB(int);
    void setColor(int, int, int);
    int getR() const;
    int getG() const;
    int getB() const;
    Color& randomizeColor(); // Randomizes color RGB values. Return by & for method chaining
    string toString() const; // print() method but returns a string
    ~Color();
};

// ADDED FROM LAB 13
void SetForegroundColor(int, int, int); // Changes cout letter color
void SetBackgroundColor(int, int, int); // Changes cout background color
void ResetColor(); // Resets console output color

int main()
{
    // Initialize variables
    const unsigned int COLORS_SIZE = 36;
    Color colors[COLORS_SIZE] = {};

    // Finally, have some fun and output color codes with color
    // Not going to color the individual elements in toString
    // Full parameter 
    cout << "FULL PARAMETER COLORS:" << endl;
    for (size_t i = 0; i < COLORS_SIZE; i++)
    {
        if (i % 4 == 0 && i != 0) cout << endl;
        colors[i] = Color().randomizeColor(); // Return randomized color object
        SetForegroundColor(colors[i].getR(), colors[i].getG(), colors[i].getB()); // Change text color to RGB values
        cout << "Color " << i << "::";
        ResetColor();
        cout << " " << colors[i].toString() << "\t";        
    }      

    cout << endl << endl; // Spacing
    return 0;
}

// COLOR CLASS
// Default constructor
Color::Color()
    : r(0), g(0), b(0) // Initialized default if none specified
{
}

// Overloaded constructor
Color::Color(int red, int green, int blue)
// Initialized default if none specified
{
    setR(red);
    setG(green);
    setB(blue);
}

void Color::setR(int Red)
{
    if (Red >= 0 && Red <= 255)
    {
        r = Red;
    }
    else
    {
        throw invalid_argument("Red value must be between 0 and 255.");
    }
}
void Color::setG(int Green)
{
    if (Green >= 0 && Green <= 255)
    {
        g = Green;
    }
    else
    {
        throw invalid_argument("Green value must be between 0 and 255.");
    }
}
void Color::setB(int Blue)
{
    if (Blue >= 0 && Blue <= 255)
    {
        b = Blue;
    }
    else
    {
        throw invalid_argument("Blue value must be between 0 and 255.");
    }
}
void Color::setColor(int Red, int Green, int Blue)
{
    setR(Red);
    setG(Green);
    setB(Blue);
}
int Color::getR() const
{
    return r;
}
int Color::getG() const
{
    return g;
}
int Color::getB() const
{
    return b;
}

// Randomize color. Return by & for method chaining
Color& Color::randomizeColor(){
    // Random number generator to create RGB
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);  // For creating colors
    setR(dist(gen));
    setG(dist(gen));
    setB(dist(gen));
    return *this;
}

// Standard toString function for class
string Color::toString() const
{
    stringstream oss;
    oss << "r: " << r << " g: " << g << " b: " << b;
    string output = oss.str();
    return output;
}

// Overriden operator<<
ostream &operator<<(ostream &os, const Color &c)
{
    os << c.toString();
    return os;
}

Color::~Color()
{
}

// Changes cout letter color
void SetForegroundColor(int r, int g, int b)
{
    cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

// Changes cout background color
void SetBackgroundColor(int r, int g, int b)
{
    cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";
}

// Resets console output color
void ResetColor()
{
    cout << "\033[0m";
}