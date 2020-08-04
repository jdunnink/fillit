
Fillit is one of the introductory projects at Codam. It is meant to familiarize students with algorithms and time complexity.
The goal of this project was to write an algorithm that could find the smallest square possible from a combination of randomly shaped figures named tetrominos.

examples of possible tetrominos:

```
.#..    .#..    #...    ###.
###.    .#..    #...    ..#.
....    ##..    #...    ....
....    ....    #...    ....
```

Each shape can only consist of four 'blocks' denoted by '#' and the entire shape is presented on a 4x4 square, with open space denoted with '.'

The input shapes are stored in a file, and then provided to the program by passing the filename as an argument. Example:

```
./fillit (source_file)
```

The solution has to consist of a square printed on the standard output. It should, with the provided shapes, generate the smallest square possible.

Given the shapes presented above, the program shows the following solution:

```
.A.BC
AAABC
..BBC
DDD.C
..D..
```

The capitalized letters indicate the order of the shapes. The first shape is denoted with 'A', the second with 'B', etc. The smallest square for this combination of shapes
is 5x5. With only four shapes, the problem is not very difficult. However, as the number of provided shapes increases, the problem becomes progressively harder to solve.


An additional requirement of this project is that, when multiple solutions are possible, the right solution is the one where the order of shapes within the square matches
the order in which they were provided to the program.

To compile the fillit executable, run the 'make' command in the root.
