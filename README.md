# linkedList-UML
In this repo. I have a program that uses a Linked list data structure to make a very simplified inventory system for a store and warehouse in C++

In this Program I have written a (vastly simplified) inventory system for a store / warehouse (like Ikea or
Costco) using C++.
This store will sell a number of Products. Each product has a StoreLocation. These locations are in the main
store area where shoppers shop. Each product may have zero or more overstock locations in the warehouse. These
are stored on skids (Figure 1) of all the same Product wrapped in plastic. We will call these WHLocations (warehouse
locations). Because WHLocations can only accept skids, they will be treated differently than StoreLocations, and
we will use inheritance to implement to two different styles of Locations.
To help us with our inventory system we will use a few different data structures. We will use the linked List
that we have seen in class, but with some modifications. We will also implement a Queue, which is a linked list but
with different rules for adding and removing. We will also use primitive arrays.

#NAME: Jigar M. Dhameliya

-Overall program
The program runs perfectly fine without any issues.

-Valgrind
I am having no errors and no memory leak in the program

to run the program 
in the command shell navigate to the directory of the program and then type "make all"
then press "./a3"

you can test the program now.
Thanks
