#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string student_name;
    int student_age;

public:
    Student(const string& name, int age) {
        student_name = name;
        student_age = age;
    }

    string GetStudentName() const {
        return student_name;
    }

    int GetStudentAge() const {
        return student_age;
    }

    void PrintInfo() const {
        cout << "Student: " << student_name << " Age: " << student_age;
    }
};

class Aspirant : public Student {
private:
    string topic;

public:
    Aspirant(const string& name, int age, const string& topic)
        : Student(name, age) {
        this->topic = topic;
    }

    string GetTopic() const {
        return topic;
    }

    void SetTopic(const string& topic) {
        this->topic = topic;
    }

    void PrintTopic() const {
        cout << "Topic: " << topic;
    }
};

class Transport {
protected:
    string transport_type;

public:
    Transport(const string& type) {
        transport_type = type;
    }

    virtual double CalculateTime() const = 0;
    virtual double CalculateCost() const = 0;

    void TravelInfo() const {
        cout << "Type: " << transport_type << " Time: " << CalculateTime() << " Cost: " << CalculateCost() << " hrivnas" << "\n";
    }
};

class Car : public Transport {
public:
    Car() : Transport("Car") {}

    double CalculateTime() const override {
        return 15.0; 
    }

    double CalculateCost() const override {
        return 60.0; 
    }
};

class Bus : public Transport {
public:
    Bus() : Transport("Bus") {}

    double CalculateTime() const override {
        return 5.0;
    }

    double CalculateCost() const override {
        return 30.0;
    }
};

class Tramvai : public Transport {
public:
    Tramvai() : Transport("Tramvai") {}

    double CalculateTime() const override {
        return 10.0;
    }

    double CalculateCost() const override {
        return 35.0;
    }
};

class Scooter : public Transport {
public:
    Scooter() : Transport("Scooter") {}

    double CalculateTime() const override {
        return 2.0;
    }

    double CalculateCost() const override {
        return 15.0;
    }
};

class Train : public Transport {
public:
    Train() : Transport("Train") {}

    double CalculateTime() const override {
        return 150.0;
    }

    double CalculateCost() const override {
        return 70.0;
    }
};

class Plane : public Transport {
public:
    Plane() : Transport("Plane") {}

    double CalculateTime() const override {
        return 150.0;
    }

    double CalculateCost() const override {
        return 600.0;
    }
};

class Pen {
protected:
    string pen_color;
    int pen_thickness;
    string pen_type;

public:
    Pen(const string& color, int thickness, const string& type) {
        pen_color = color;
        pen_thickness = thickness;
        pen_type = type;
    }

    void Draw() const {
        cout << "Drawing with Color: " << pen_color << " Thickness: " << pen_thickness << " Type: " << pen_type;
    }
};

class Brush {
protected:
    string fill_color;

public:
    Brush(const string& color) {
        fill_color = color;
    }

    void Fill() const {
        cout << "Filling with Color: " << fill_color;
    }
};

class SolidBrush : public Brush {
public:
    SolidBrush(const string& color) : Brush(color) {}
};

class GradientBrush : public Brush {
protected:
    string gradient_colors[2];

public:
    GradientBrush(const string& start_color, const string& end_color)
        : Brush(start_color) {
        gradient_colors[0] = start_color;
        gradient_colors[1] = end_color;
    }
};

class HatchBrush : public Brush {
private:
    string hatch_color;

public:
    HatchBrush(const string& fill_color, const string& hatch_color)
        : Brush(fill_color), hatch_color(hatch_color) {}

    void Fill() {
        cout << "Fill Color: " << fill_color << " Hatch Color: " << hatch_color;
    }
};

class TextureBrush : public Brush {
private:
    string texture_path;

public:
    TextureBrush(const string& fill_color, const string& path)
        : Brush(fill_color), texture_path(path) {}

    void Fill()  {
        cout << "Fill Color: " << fill_color << " Texture Path: " << texture_path;
    }
};

class VisualBrush : public Brush {
private:
    string control_identifier;

public:
    VisualBrush(const string& fill_color, const string& identifier)
        : Brush(fill_color), control_identifier(identifier) {}

    void DrawVisual() const {
        cout << "Fill Color: " << fill_color << " Identifier: " << control_identifier;
    }
};

class LinearGradientBrush : public GradientBrush {
public:
    
    string LinearGradientBrush;
};

class RadialGradientBrush : public GradientBrush {
public:

    string RadialGradientBrush;
};

class Geometry {
protected:
    Pen geometry_pen;
    Brush* geometry_brush;

public:
    Geometry(const Pen& pen, Brush* brush)
        : geometry_pen(pen), geometry_brush(brush) {}

    void Draw() const {
        geometry_pen.Draw();
        if (geometry_brush) {
            geometry_brush->Fill();
        }
    }
};

class Rectangle : public Geometry {
public:
    Rectangle(const Pen& pen, Brush* brush)
        : Geometry(pen, brush) {}
};

class Ellipse : public Geometry {
public:
    Ellipse(const Pen& pen, Brush* brush)
        : Geometry(pen, brush) {}
};

class Polyline : public Geometry {
public:
    Polyline(const Pen& pen, Brush* brush)
        : Geometry(pen, brush) {}
};

class Font {
private:
    int font_size;
    string font_family;
    bool is_bold;
    bool is_italic;
    bool is_underlined;
    string font_color;

public:
    Font(int size, const string& family, bool bold, bool italic, bool underlined, const string& color)
        : font_size(size), font_family(family), is_bold(bold), is_italic(italic), is_underlined(underlined), font_color(color) {}

    void SetFontSize(int size) {
        font_size = size;
    }

    void SetFontFamily(const string& family) {
        font_family = family;
    }

    void SetBold(bool bold) {
        is_bold = bold;
    }

    void SetItalic(bool italic) {
        is_italic = italic;
    }

    void SetUnderlined(bool underlined) {
        is_underlined = underlined;
    }

    void SetFontColor(const string& color) {
        font_color = color;
    }

    void DisplayFontInfo() const {
        cout << "Font Size: " << font_size << " Font Family: " << font_family << " Bold: " << (is_bold ? "Yes" : "No") << " Italic: " << (is_italic ? "Yes" : "No")
            << " Underlined: " << (is_underlined ? "Yes" : "No") << " Font Color: " << font_color << "\n";
    }
};

class Button : public Rectangle, public Font {
public:
    Button(const Pen& pen, Brush* brush, int font_size, const string& font_family, bool bold, bool italic, bool underlined, const string& font_color)
        : Rectangle(pen, brush), Font(font_size, font_family, bold, italic, underlined, font_color) {}

    void DisplayButtonInfo() const {
        cout << "Button Information:" << "\n";
        Draw();
        DisplayFontInfo(); 
    }
};

int main() {


    Aspirant aspirant("Bob Dol", 25, " Designer");
    aspirant.PrintInfo();        
    aspirant.PrintTopic(); 

    Car car;
    car.TravelInfo();

    Bus bus;
    car.TravelInfo();

    Tramvai tramvai;
    tramvai.TravelInfo();

    Scooter scooter;
    scooter.TravelInfo();

    Train train;
    train.TravelInfo();

    Plane plane;
    plane.TravelInfo();

    SolidBrush solid_brush("White");
    solid_brush.Fill();

    HatchBrush hatch_brush("White", "Cross");
    hatch_brush.Fill();

    TextureBrush texture_brush("Purple", "path/to/kotik.jpg");
    texture_brush.Fill();

    VisualBrush visual_brush("Blue", "Control123");
    visual_brush.DrawVisual();

    Font button_font(10, "Arial", true, false, false, "black");
    Button my_button(Pen("Black", 2, "Solid"), &texture_brush, 14, "Verdana", true, false, true, "Blue");
    my_button.DisplayButtonInfo();

    return 0;
}


