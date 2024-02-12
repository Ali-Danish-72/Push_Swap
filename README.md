# Push_Swap
This project is about using a set of operations in an algorithm to sort a list of integers using two stacks, `a` and `b` respectively. The program is called `push_swap` and the integers are provided to the program as its arguments. The goal is to get the smallest integer to the top and the largest integer at the bottom of stack `a` as efficiently as possible.

# Operations
There are a total of 11 operations the program can use. They can be organized into **swap**, **rotate**, **reverse rotate** and **push** operations.

**Swap Operations**
| Operation | Description |
|--|--|
|`sa`|Swaps the first two elements of stack `a`|
|`sb`|Swaps the first two elements of stack `b`|
|`ss`|Executes `sa` and `sb` at the same time.|

**Rotate Operations**
| Operation | Description |
|--|--|
|`ra`|Rotates the top element of stack `a` to the bottom.|
|`rb`|Rotates the top element of stack `b` to the bottom.|
|`rr`|Executes `ra` and `rb` at the same time.|

**Reverse Rotate Operations**
| Operation | Description |
|--|--|
|`rra`|Rotates the bottom element of stack `a` to the top.|
|`rrb`|Rotates the bottom element of stack `b` to the top.|
|`rrr`|Executes `rra` and `rrb` at the same time.|

**Push Operations**
| Operation | Description |
|--|--|
|`pa`| Pushes the top node in stack `b` to the top of stack `a`.
|`pb`| Pushes the top node in stack `a` to the top of stack `b`.

# Overview
The program must parse the arguments and ensure that all of the arguments are valid. Things that are considered invalid inputs are no parameters, duplicate arguments, numbers outside the range of an integer type, non-numeric parameters and empty strings.

In case of an invalid input being detected, the program must print "Error\n" to the STDERR and exit the program cleanly, ensuring there are no leaks. If the parameters are parsed to be completely valid, the program must display each operation needed to sort the numbers. Each operation must be followed by a new line on STDOUT.

# Algorithm

For my attempt at this project, I used the algorithm called Mechanical Turk. This algorithm starts by pushing 2 nodes to stack `b` and for each subsequent node in stack `a`, it identifies  where the node should end up in stack `b` and which node needs the least amount of operations to be able to reach that position in stack `b`. The pushes to stack `b` need to result in the numbers being sorted in a descending order. This is to allow the pushes back to stack `a` to be in the ascending order. Once all the numbers are sorted in stack	`b`, they are pushed back to stack `a`.

# Performance
For 3 parameters, it displays 1 or 2 moves.

For 5 parameters, it displays under 10 moves.

For 100 parameters, it displays under 650 moves.

For 500 parameters, for 75% of the cases tested, it displays under 5,500 moves.

`WORKS ON MY MACHINE`

# Resources
I used this article on [Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) and this [GitHub Repository](https://github.com/ayogun/push_swap) to understand the algorithm well.
To help me visualize the output from the `push_swap` program, I used this [Visualizer](https://github.com/10257/push_swap_viz_kivy).

> ⚠️ **Warning:** This public repository is meant to be used for gaining inspiration and boost your imagination of how the logic should work. You should not use these resources to try and cheat your way through the projects.

> Written with [StackEdit](https://stackedit.io/).
