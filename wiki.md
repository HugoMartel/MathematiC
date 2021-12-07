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

Our language follows three step to work efficiently :

### 1. First you need to declare your variables

```
// Declarations
var a = 1;
```

### 2. Second you need to write your functions and your main code

```
/   if z<y {
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

### 3. Third you declare the style and intervalle for the curve

```
// Draw Functions
draw fonction1 in [-8,8], g {
    color: ["red", "#00FF00"],
    style: ["dashed", "solid"],
    label: "Fonction 1"
}
```
---

## II. Variables

To declare a variable in our language you need to use `'var ='`

You can then name your variable and give it the value you want :

```
var variable1 = 1;
var anotherVariable = 3;
var variable3;
```

You can only use alphanumerical character and you end the line with `';'`.
You will notice that you can also chose to not assign any value to your variable it will be **0** as default.

There is also some variables already defined such as :

```
e = 2.71828182845904523536
phi = 1.61803398874989484820
pi = 3.14159265358979323846
```

---

## III. Functions

To declare a function you need to first use the key word `'def'`

Then you put the **name** of your function followed by `'functionName : (x) => {'`

You can put your function's instructions and end it with `'}'`

A full exemple will looks like that :

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

---

## V. Index

---

## VI. Keyboard Shortcuts  
You can of course use keyboard shortcuts in the program, some of them can be used everywhere, some other only work when you're typing code,  


| keyboard input |   output    |
|----------------|-------------|
| CTRL + O       | open  file |
| CTRL + S       | save file   |
| CTRL + C       | copy        |
| CTRL + V       | paste       |
| CTRL + X       | cut         |
| CTRL + Q       | select all  |
| CTRL + W       | undo        |
| CTRL + Y       | redo        |

---
