# MathematiC

![Logo](./img/banner.png)

A small function visualizer langage to be able to quickly draw a Mathematical funtion.

# Libraries used
- cmake
- flex/bison
- SDL2 (coupled w/ SDL2-Image and SDL2-ttf)
- [nanogui-sdl](https://github.com/dalerank/nanogui-sdl) (modified version to support multiline textbox and Graph drawing)

# Interface

![UI Test](./img/TestInterface.png)

# Code examples

```
var a = 1;
var b = 2;
var c = 3;

def fonction1: (x) => {
    return a*x^2 + b*x + b;
}

draw fonction1 in [-8..8] {
    color: red,
    label: "Fonction 1"
}
```

```
def f: (x) => {
    
    return cos(x);
}

def g: (x) => {
    
    return sin(x);
}

drawParam f, g {
    color: green,
    ymin: 0,
    ymax: 4
}
```

```
def sg: (t) => {
    if (t < 0) {
        return -1;
    } else {
        return 1;
    }
}

draw sg in [-1..1];
```

# Compile
```
cd build
cmake ..
cmake --build .
../test
```
