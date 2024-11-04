# An implementation for a database in C. 

## Overview

This project involves the creation and manipulation of various database tables using C. The project aims to implement operations on different relations like CR, SNAP, CDH, CP, and CSG using hash tables. These tables store information related to courses, students, and their relationships. The main purpose of this project is to create, search, and manage these records effectively through command-line interfaces.

## Features

Implementation of Hashtables: Custom hash tables to store and efficiently retrieve information related to student and course data.

Operations on Database Tables: Functions to insert, delete, and lookup entries in multiple database relations, including CR, SNAP, CDH, CP, and CSG.

Query Functions: Functions such as Part2_1 and Part2_2 that allow users to search for students and their courses or locations based on given criteria.

Interactive REPL: A Read-Eval-Print-Loop (REPL) interface to allow the user to interactively query the data, including:

Finding a student's grade for a course.

Determining where a student is during a particular hour on a specific day.

How to Run the Project

## Compilation: Compile all the .c source files with a C compiler (such as gcc). Use the following command:

gcc -o database_project main.c init.c part3.c -I.

Execution: Run the executable generated after compilation:

./database_project

Code Components

Main Program: The main() function initializes the hash tables, inserts sample data, and starts the REPL interface for querying.

Part2_1 and Part2_2: These functions help answer the questions:

"Where is Name's grade in Course?"

"Where is Name at Hour on Day?"

Insert, Lookup, Delete: There are functions to insert, lookup, and delete entries in each of the relations (CR, SNAP, CDH, CP, CSG). The insertion is done using hashing for efficient storage and retrieval.

## Example Queries

1. Querying a Student's Grade in a Course

Run the REPL and enter the student's name and course to get their grade:

CSC173 Project 4 :Where is Name's grade in Course?
Enter an input Name("quit" to quit): John Doe
Enter an input Course: CSC171
The grade of the person in question inside the course is: A

2. Querying Student Location on a Given Day and Hour

Run the REPL and enter the student's name, day, and hour to find their location:

CSC173 Project 4 :Where is Name at Hour on Day?
Enter an input Name("quit" to quit): Jane Smith
Enter an input Day: Monday
Enter an input Hours: 14:00
The person in question is in Hutchison Hall 141 at the time being questioned

## Dependencies

stdio.h: For standard input-output operations.

part3.h and init.h: Header files that contain function prototypes and structures used in the implementation.

## How It Works

Hash Tables are used to store and manage the data for each of the relations.

Data Insertion: The main function inserts sample data to populate the hash tables, making them ready for queries.

Interactive Search: Users can search for information using the REPL, which provides a user-friendly interface to access the database.

## Collaborators:
Minh, 
Shun, 
Fenway
