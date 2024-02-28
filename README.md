
# Fract-ol 42

One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.


## Screenshots

![Fract-ol](https://github.com/Anadal-g/fractol/blob/main/screenshot/Screen%20Shot%202024-02-28%20at%203.07.12%20PM.png)


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

<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td><kbd>&nbsp;W&nbsp;</kbd><kbd>&nbsp;A&nbsp;</kbd><kbd>&nbsp;S&nbsp;</kbd><kbd>&nbsp;D&nbsp;</kbd> or <kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;-&nbsp;</kbd>, <kbd>&nbsp;+&nbsp;</kbd> or <kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;space&nbsp;</kbd></td><td>Change color scheme</td></tr>
  <tr><td><kbd>&nbsp;1&nbsp;</kbd>, <kbd>&nbsp;2&nbsp;</kbd>, <kbd>&nbsp;3&nbsp;</kbd>, <kbd>&nbsp;4&nbsp;</kbd>, or <kbd>&nbsp;5&nbsp;</kbd></td><td>Switch fractals</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit fract-ol</td></tr>
</table>

## Screeshots

Mandelbrot set
![Fract-ol mandelbrot](https://github.com/Anadal-g/fractol/blob/main/screenshot/Screen%20Shot%202024-02-28%20at%2012.23.03%20PM.png)

Julia set
![Fract-ol julia](https://github.com/Anadal-g/fractol/blob/main/screenshot/Screen%20Shot%202024-02-28%20at%2012.51.01%20PM.png)
Another Julia set
![Fract-ol julia2](https://github.com/Anadal-g/fractol/blob/main/screenshot/Screen%20Shot%202024-02-28%20at%2012.55.01%20PM.png)

Burning ship
![Fract-ol ship](https://github.com/Anadal-g/fractol/blob/main/screenshot/Screen%20Shot%202024-02-28%20at%2012.51.39%20PM.png)
