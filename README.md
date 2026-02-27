# CS-300 Portfolio Reflection  
**Allie Lankford**  
**CS-300 DSA Analysis and Design**  
**Project One and Two**  

## Reflection  

**What was the problem you were solving in the projects for this course?**  
In these projects, I was working on building an advising assistance program for the Computer Science department. The main problem was how to organize and store course information efficiently so advisors could quickly look up courses, see prerequisites, and print a full list of courses in alphanumeric order. I had to think about different ways to store and access the data using vectors, hash tables, and binary search trees.  

**How did you approach the problem? Consider why data structures are important to understand.**  
I started by analyzing the course data and considering how each data structure would handle the information. I wrote pseudocode for each structure to see how I could load, search, and sort the courses. Understanding how vectors, hash tables, and binary search trees work helped me choose the right structure. I decided to implement a binary search tree because it keeps the courses sorted automatically and allows fast searching and inserting. This made the program easier to use for advisors.  

**How did you overcome any roadblocks you encountered while going through the activities or project?**  
One challenge was making sure the BST handled duplicate courses and prerequisites correctly. I overcame this by adding checks when inserting courses and limiting the number of prerequisites. Another challenge was sorting and printing courses in order. Since the BST naturally keeps them in order, I realized I could use an in-order traversal instead of extra sorting, which simplified the code.  

**How has your work on this project expanded your approach to designing software and developing programs?**  
These projects helped me see the importance of planning before coding. Writing pseudocode first made it easier to translate ideas into working C++ code. I also learned how different data structures can affect program efficiency, memory usage, and ease of use. This experience made me more thoughtful about choosing the right structure for a problem and designing programs in a logical, organized way.  

**How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**  
Working on these projects has taught me to keep my code clean and structured. I used clear variable names, comments, and functions for each task, which makes it easier to read and understand later. By separating tasks like loading data, printing courses, and searching for a course, I created a program that is adaptable if I need to make changes or add new features. I also practiced handling errors and user input carefully, which makes the program more reliable.
