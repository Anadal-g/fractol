
# Fract-ol 42

One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.


## Screenshots

![App Screenshot](https://es.wikipedia.org/wiki/Conjunto_de_Mandelbrot#/media/Archivo:Mandelbrot0.jpg)


## Installing and Compiling Fract-ol

Clone the repository

git clone `https://github.com/Anadal-g/fractol.git` 




## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

`make`

`./fractol <type> <options>` 

The diferent types are:

`./fractol mandelbrot` 

`./fractol ship`

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0

`./fractol julia <values (-0.7 -0.3)>`

## Controls 

While Fractol is running, the following set of controls are available:


## Screeshots

Mandelbrot set


Julia set



Burning ship