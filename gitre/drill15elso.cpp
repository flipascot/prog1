/* g++ drill15elso.cpp ../lib_files/Graph.cpp ../lib_files/Window.cpp ../lib_files/GUI.cpp ../lib_files/Simple_window.cpp -o drill15elso `fltk-config --ldflags --use-images` */ 
#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"
#include "../lib_files/fltk.h"
#include "../lib_files/std_lib_facilities.h"


double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }


int main(){
    using namespace Graph_lib;
    
    Point t(100,100);
    Simple_window win(t,600,600, "Function graphs.");
    Axis xa {Axis::x, Point{100,300}, 400, 20, "1 = = 20 pixels"};
    Axis ya {Axis::y, Point{300,500}, 400, 20, "1 = = 20 pixels"};
    xa.set_color(Color::red);
    ya.set_color(Color::red);
    win.attach(xa);
    win.attach(ya);
    constexpr int x_max = 600;
    constexpr int y_max = 600;
    constexpr int range_min = -10;
    constexpr int range_max = 11;
    constexpr int number_points = 400;
    constexpr int x_scale = 20;
    constexpr int y_scale = 20;
    constexpr int x_orig = x_max / 2;
    constexpr int y_orig = y_max / 2;
    Point orig {x_orig, y_orig};
    
    Function one_line(one, range_min, range_max, orig, number_points, x_scale, y_scale);
    
    Function slope_line(slope, range_min, range_max, orig, number_points, x_scale, y_scale);
    
    Text text{ Point{100,390}, "x/2" };
    Function square_line(square, range_min, range_max, orig, number_points, x_scale, y_scale);
    Function cos_line(cos, range_min, range_max, orig, number_points, x_scale, y_scale);
    cos_line.set_color(Color::blue);
    Function sloping_cos_line(sloping_cos, range_min, range_max, orig, number_points, x_scale, y_scale);
    win.attach(one_line);
    win.attach(slope_line);
    win.attach(text);
    win.attach(square_line);
    win.attach(cos_line);
    win.attach(sloping_cos_line);
    win.wait_for_button();
}
