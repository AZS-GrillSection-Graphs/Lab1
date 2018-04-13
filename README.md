# Graphs Lab1

# Requirements
* python numpy (installation on Ubuntu):
```
$ sudo apt-get install python3-numpy 
```
* python matplotlib (installation on Ubuntu):
```
$ sudo apt-get install python3-matplotlib
```
# Functionality
* Graph Representation Conversion:

Program converts graph representation included in file graphRep.txt to other types of graphs representations (Incidence Matrix, Adjacency Matrix, Adjacency List). 

In order to convert program should be runned without any arguments. 
Converted graph is visualized.

Example of graphRep.txt:
```
MS
0 1 1 1 1 0 
1 0 1 1 1 1 
1 1 0 1 1 0 
1 1 1 0 0 1 
1 1 1 0 0 1 
0 1 0 1 1 0 
```
  
  

* Random Graphs Generation:

Program generates random graphs G(n, p) or G(n, a), where n is number of vertexes, p is probability that two vertexes are linked and a is amount of edges in graph. 

To generate random graph program should be runned with arguments: "probability/amount" number_of_vertexes probability/amount_of_edges.

Example G(10, 0.75):
```
./Lab01.out probability 10 0.75
```
Example G(20, 132):
```
./Lab01.out amount 20 132
```

Generated graph is visualized as well.
