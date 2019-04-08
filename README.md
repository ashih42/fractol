# fractol
Render the [Julia Set](https://en.wikipedia.org/wiki/Julia_set), [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set), and more fractals in C using [minilibx](https://github.com/qst0/ft_libgfx). (42 Silicon Valley)

<p float="left">
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/julia.png" width="280" />
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/mandelbrot.png" width="280" /> 
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/mandeldrop.png" width="280" />
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/spiral_rose.png" width="280" />
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/elysian_veil.png" width="280" /> 
  <img src="https://github.com/ashih42/fractol/blob/master/Screenshots/void_star.png" width="280" />
</p>

## Prerequisites

You are on macOS with `gcc` and `make` installed.

## Compiling

```
make
```

## Running

Display fractals at indices `n` ...

```
./fractol [n ...]
```
### Fractals
1. Mandelbrot Set
2. Julia Set
3. Burning Ship
4. Burning Ship (Julia cross-section)
5. Tricorn
6. Tricorn (Julia cross-section)
7. Mandelbrot ^ 3
8. Julia ^ 3
9. Mandelbrot ^ 4
10. Julia ^ 4
11. Mandelbrot ^ 8
12. Julia ^ 8
13. Mandeldrop
14. Mandeldrop (Julia cross-section)
15. Triplet Mitosis
16. Triplet Mitosis (Julia cross-section)
17. Hyperbolic Triangulum
18. Hyperbolic Triangulum (Julia cross-section)
19. Spiral Rose
20. Spiral Rose (Julia cross-section)
21. Elysian Veil
22. Elysian Veil (Julia cross-section)
23. Void Star
24. Void Star (Julia cross-section)

## Controls

### Top-level Controls
* `Spacebar` Reset view and options.
* `Escape` Terminate all fractals.

### Viewport Controls
* `Mouse scroll wheel` Zoom in/out.
* `Drag LMB` Translate viewport.
* `Arrow Keys` Translate viewport.

### Fractal Controls
* `Left Shift` + `Move Mouse` Set C (for Julia types).
* `Left Control` + `Move Mouse` Set Z (for Mandelbrot types).
* `+` Increase max iterations.
* `-` Decrease max iterations.
* `Tab` Select next color scheme.
* `W` Select next color-mapping function.
* `E`Toggle smooth coloring.
* `Q` Toggle psychedelica.






