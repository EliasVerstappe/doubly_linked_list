# Doubly linked list
___

Compile with `gcc .\main.c` and run with `.\a.exe`


#### Output
```
Inserting values...
        ... done!

Printing list front to back:
Value: [   0 ]
Value: [   1 ]
Value: [   2 ]
Value: [   3 ]
Value: [   4 ]
Value: [   5 ]
Value: [   6 ]
Value: [   7 ]
Value: [   8 ]
Value: [   9 ]

Printing list back to front:
Value: [   9 ]
Value: [   8 ]
Value: [   7 ]
Value: [   6 ]
Value: [   5 ]
Value: [   4 ]
Value: [   3 ]
Value: [   2 ]
Value: [   1 ]
Value: [   0 ]

Fetching node with index 3 ...
        ... Value of node: 3

Printing list front to back, giving third node as argument:
Value: [   0 ]
Value: [   1 ]
Value: [   2 ]
Value: [   3 ]
Value: [   4 ]
Value: [   5 ]
Value: [   6 ]
Value: [   7 ]
Value: [   8 ]
Value: [   9 ]

Deleting at index 5 ...
        ... Node deleted

Printing list:
Value: [   0 ]
Value: [   1 ]
Value: [   2 ]
Value: [   3 ]
Value: [   4 ]
Value: [   6 ]
Value: [   7 ]
Value: [   8 ]
Value: [   9 ]

        & backwards:
Value: [   9 ]
Value: [   8 ]
Value: [   7 ]
Value: [   6 ]
Value: [   4 ]
Value: [   3 ]
Value: [   2 ]
Value: [   1 ]
Value: [   0 ]

Inserting new node with value 22 at index 3 ...

Printing list:
Value: [   0 ]
Value: [   1 ]
Value: [   2 ]
Value: [  22 ]
Value: [   3 ]
Value: [   4 ]
Value: [   6 ]
Value: [   7 ]
Value: [   8 ]
Value: [   9 ]

        & backwards:
Value: [   9 ]
Value: [   8 ]
Value: [   7 ]
Value: [   6 ]
Value: [   4 ]
Value: [   3 ]
Value: [  22 ]
Value: [   2 ]
Value: [   1 ]
Value: [   0 ]
```