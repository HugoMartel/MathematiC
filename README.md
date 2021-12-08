# MathematiC

![Logo](./img/banner.png)

A small function visualizer langage to be able to quickly draw a Mathematical funtion.  
In order to learn how to use it, check the [Wiki](wiki.md).

# Libraries used
- make
- flex/bison
- SDL2 & OpenGL3
- [imgui](https://github.com/ocornut/imgui)

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

draw f, g {
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

**Use commands in the root folder of the cloned repo**

*Main Program:*
```
make all
./MathematiC
```

*Unit Testing:*
```
make unit_test
```

*Generate Documentation for the source code:*
```
doxygen && cp -rv img doc/html/
```
