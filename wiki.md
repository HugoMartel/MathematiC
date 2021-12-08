# WIKI

---

#### You will be able to find here everything you need in order to code everything you want, you will be able to find infos about the syntax and how everything work.

---

## Summary

1. [Structure](#i-structures)
2. [Variables](#ii-variables)
3. [Functions](#iii-functions)
4. [Display](#iv-display)
5. [Index](#v-index)
6. [Keyboard Shortcuts](#vi-keyboard-shortcuts)

---

## I. Structures

Our language is built around **3** parts:

### 1. Variables declaration

```
// Declarations
var a = 1;
var b = cos(0);
var c = 4 / 3;
var y;
var z;
```

### 2. Functions definition

```
// Functions
def f: (x) => {
   if z<y {
        if y > 0 {
            y = sin(2);
            z = x + y + pi;
        } else {
            z = cos(3);
        }
    } else {
        z =  6*7;
    }
    return a*x^2 + b*x + c;/* simple polynomial */
}

def g: (x) => {
    x += 2;
    return 2*sin(x);
}
```

### 3. Drawing parameters

```
// Draw
draw fonction1 in [-8,8], g {
    color: ["red", "#00FF00"],
    style: ["dashed", "solid"],
    label: "Fonction 1"
}
```

---

## II. Variables

To declare a variable in our language you need to use `var <name> = <value>;`

You can then name your variable and give it the value you want :

```
var variable1 = 1;
var anotherVariable = 3;
var variable3;
```

You can only use alphanumerical characters and must end a line with `';'`.
You will notice that you can also choose not to assign any value to your variable, it will then take **0** as a default value.

There also are some variables predefined such as :

```
e = 2.71828182845904523536
phi = 1.61803398874989484820
pi = 3.14159265358979323846
```

---

## III. Functions

To declare a function, you firstly need to use the key word `def`

Then you put the **name** of your function followed by `functionName : (x) => {`

You can put your function's instructions and end it with a `}`

*Full example:*

```
def fonction1: (x) => {
    // Function Instructions
    if z<y and y>0 {
        if y > 0 {
	    y = sin(2);
	    z = x + y + pi;
	} else {
	    z = cos(3);
	}
    } else {
        z =  6*7;
    }
    return a*x^2 + b*x + c;/* simple polynomial */
}
```

---

## IV. Display

To display the functions you have created you will have to call `draw` and then set the optional parameters.

Here is an example for every parameter you can set with two functions :

```
// If the interval isn't declare default interval will be [-10,10]
draw f in [-8,8], g {
    // Set color by using basic names or RGB hexadecimal code
    color: ["red", "#00FF00"],
    // Set the style of your curve
    style: ["dashed", "solid"],
    // Set a label on your curve
    label: "Fonction 1",
    // Set xmin, ymin, xmax and ymax for your drawing window
    xmin: -5,
    ymin: -5,
    xmax: 5,
    ymax: 5
}
```

*Here we draw f and g, we specify an interval for f which means that the function will only be drawable on this interval, however g is drawable everywhere ([`[DBL_MIN,DBL_MAX]`](https://www.cplusplus.com/reference/cfloat/))*

### List of parameter you can set in **draw** :

- `color` : Color of the curves using the color name or the hexadecimal code

- `style` : Style of the curves { `"solid"`, `"filled"`, `"dotted"`, `"hist"` }

- `label` : Label of the function widget

- `xmin, xmax, ymin, ymax` : Rectangle dimensions in which to draw the curve

*`color` and `style` parameters will be called using `[ arg1, arg2, ... ]` matching the number of curves chosen to be drawn.*

---

## V. Index

### /!\ Reserved words

- in
- var
- def
- return

***Can't be used in variable names, same goes words defined after this list***

### Predefined variables

- pi
- phi
- e

### Basic Operators

- \+ / +=
- \- / -=
- \* / *=
- \/ / /=
- \^
- or
- and
- !
- \<
- \>
- \<=
- \>=
- ==
- !=

### Mathematical function :
- cos
- sin
- tan 
- arccos
- arcsin
- arctan
- cosh
- sinh
- tanh
- arccosh
- arcsinh
- arctanh
- pow
- sqrt
- exp
- log

### Logical function

**IF**

```
if condition {
    instruction
} 
```
It can also be used with multiple condition using `'and'` or `'or'` between two conditions


**IF/ELSE**

```
if condition {
    instruction
} else {
    instruction
}
```

**FOR**

```

```

**WHILE**

```

```

### Display function

**DRAW**

```
draw functionName in [interval], otherFunctionName, ... {
    parameter1,
    parameter2,
    ...    
}
```


### Comments
- multiline: /\*\*/
- singleline: // 

---

## VI. Keyboard Shortcuts  
You can of course use keyboard shortcuts in the program, some of them can be used everywhere, some other only work when you're typing code,  


| keyboard input |   output    |
|----------------|-------------|
| CTRL + O       | open  file  |
| CTRL + S       | save file   |
| CTRL + C       | copy        |
| CTRL + V       | paste       |
| CTRL + X       | cut         |
| CTRL + Q       | select all  |
| CTRL + W       | undo        |
| CTRL + Y       | redo        |
