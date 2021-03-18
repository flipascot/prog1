/* 
g++ sdrill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch `fltk-config --ldflags --use-images`
*/ 
#include "Simple_window.h"
#include "Graph.h"

int main(){

    using namespace Graph_lib;

    Point tl{100,100};

    Simple_window ablak {tl,800,1000,"Simple window"};


    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;
    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
    grid.add(Point{x,0},Point{x,y_size});
    for (int y = y_grid; y<y_size; y+=y_grid)
    grid.add(Point{0,y},Point{x_size,y});

    Rectangle atlo1{Point{0,0},100,100};
    atlo1.set_color(Color::red);
    Rectangle atlo2{Point{100,100},100,100};
    atlo2.set_color(Color::red);
    Rectangle atlo3{Point{200,200},100,100};
    atlo3.set_color(Color::red);
    Rectangle atlo4{Point{300,300},100,100};
    atlo4.set_color(Color::red);
    Rectangle atlo5{Point{400,400},100,100};
    atlo5.set_color(Color::red);
    Rectangle atlo6{Point{500,500},100,100};
    atlo6.set_color(Color::red);
    Rectangle atlo7{Point{600,600},100,100};
    atlo7.set_color(Color::red);
    Rectangle atlo8{Point{700,700},100,100};
    atlo8.set_color(Color::red);
    Image ii1{Point{600,300},"bmw.jpg"};
    Image ii2{Point{500,0},"bmw.jpg"};
    Image ii3{Point{0,400},"bmw.jpg"};





    ablak.attach(grid);
    ablak.attach(atlo1);
    ablak.attach(atlo2);
    ablak.attach(atlo3);
    ablak.attach(atlo4);
    ablak.attach(atlo5);
    ablak.attach(atlo6);
    ablak.attach(atlo7);
    ablak.attach(atlo8);
    ablak.attach(ii1);
    ablak.attach(ii2);
    ablak.attach(ii3);



    for (int ix=0; ix<800; ix+=100)   {
    for (int iy=0; iy<800; iy=iy+100)
   
    {Image ii{Point{ix,iy},"xd.jpg"};
    ablak.attach(ii); 
    ablak.wait_for_button();}}






}
