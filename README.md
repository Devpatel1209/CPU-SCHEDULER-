         Project Title

 CPU Scheduler

Project Description

This project implements a sophisticated CPU scheduler in C++ capable of handling multiple scheduling algorithms. The scheduler is designed to manage the execution of processes efficiently by deciding which process should utilize the CPU and for how long. The implemented algorithms include First Come First Serve (FCFS), Shortest Job Next (SJN), Priority Scheduling, Round Robin (RR), Multilevel Queue Scheduling, and Multilevel Feedback Queue Scheduling. A frontend interface is provided to visualize the scheduling decisions and demonstrate the optimality of the scheduler through various statistics and charts.

             HOW TO RUN A PROJECT 

first of all the the file name CPU SCHEDULER JSON will give a json output, from which you can directly acess the json outptut and link with the frontend part where you can see the output of the desrised result of the project,.
the frontend part inculde basic structure of the web were you can the OUTPUT all though the user intereaction part is not inculded mean if you run the file it gives the direct result for exmaple the ID, BURST TIME,ARIVAL TIME. beacuse i wanted to create a simple code where every body can undersatnd, if you wish to make a user intreaction freindly you just need to apply the simple logic of c++ and remove some changes and makes the user friendly
i have also put some comment to read a perticular code of this file, basically it provide the basic knowlege of cpu scheduler where you can interpret the  output and make desicion  out of it. and the next part i will be explaining the code part from where i get those ideas and make this code workable also i will tell some some basic part from which integrate all those code and work thinfg happen. and also i put some refrence where i got some library and put in my code and it reduces my time and effort.

    Although i have put all file sperated so that everybody can understand, if you want to use it, you can either launch all in replit or in glitch websites, this some online website where you acess it directly   

              THE INTERNAL WORKING OF THE PROJECT 

The project is a sophisticated CPU scheduler implemented in C++ that can handle multiple scheduling algorithms. It features a backend that simulates scheduling decisions and a frontend that visualizes these decisions. The backend is connected to the frontend via an HTTP server that serves scheduling results as JSON data.

here is the code explaination of each every line in the given file.

Task Class: Represents a process or task.

Attributes:

id: Unique identifier for the task.

arrival_time: Time at which the task arrives in the ready queue.

burst_time: Total time required by the task to complete.

priority: Priority level of the task.

remaining_time: Time remaining for the task to complete.

state: Current state of the task (e.g., "new", "running", "completed").



Scheduler Base Class: Abstract class that defines the interface for scheduling algorithms.

Methods:

schedule(): Pure virtual function that must be implemented by derived classes to perform scheduling.



FCFS Scheduler Class: Implements the First Come First Serve scheduling algorithm.

Methods:

schedule(): Sorts tasks by arrival time and simulates their execution in that order


tasks: A vector of Task objects representing the tasks to be scheduled.


runScheduler(): Creates an instance of FCFSScheduler and runs the schedule() method on the tasks vector.

getTasksAsJson(): Converts the tasks vector to JSON format.

Main Function: Runs the scheduler. Starts an HTTP server that listens on port 8080 and serves the scheduling results as JSON.




HTML/JavaScript Frontend:

Elements: A heading to display the title. A div (scheduler-output) to display the scheduling results.

JavaScript:

fetchSchedulingData(): Fetches scheduling data from the backend.
displaySchedule(data): Displays the fetched data in the scheduler-output div.
The function fetchSchedulingData is called when the window loads to automatically fetch and display the scheduling results.

Running the Scheduler:

The runScheduler() function creates an instance of the FCFSScheduler and calls its schedule() method with the tasks vector.
The schedule() method sorts the tasks by arrival time and simulates their execution, updating their state to "running" and then "completed."
Serving the Results:

The main function starts an HTTP server using cpp-httplib.
The server listens on port 8080 and responds to GET requests at the /schedule endpoint by returning the tasks vector in JSON format.
Frontend Interaction:

The HTML frontend fetches the scheduling results from the backend using the Fetch API.
The fetched data is displayed in the scheduler-output div, showing the state of each task.
Visualization:

The frontend visualizes the scheduling decisions, demonstrating which tasks were executed and their states, thus showcasing the scheduling algorithm's behavior.

    IMPORTANT LEARNING TAKEAWAYS

first of all 1.Understanding of Scheduling Algorithms: Deepened knowledge of various CPU scheduling algorithms and their practical applications.


2.Backend-Frontend Integration: Learned how to integrate a C++ backend with a web-based frontend using HTTP communication. where before this project i did not know anything about webd but this project fullfil the gap where i learned the most important partv of this project where just output is not an answer you have sshow in the web and stat

3.Real-time Visualization: Gained experience in creating real-time visualizations to effectively demonstrate algorithm performance.

And last but not the least the importance of using " using namespace std". in general we wrote this line before we are plaing in c++ without knowing the importants, but  in this project  it give me trouble of writing it before cause it confuse the compiler to read when i was using #incude "nlohmann/json.h"
it give me error forcing me to lear to write "std::" instead of " using namespace std".

           THE ROSOURCES/REFERENCE 
           cpp-httplib GitHub Repository: For the HTTP server implementation in C++.
         nlohmann/json GitHub Repository: For the JSON handling in C++.
         CPlusPlus.com and Stack Overflow: For various C++ programming tips and problem-solving.
        Mozilla Developer Network (MDN): For web development resources and JavaScript documentation.
           

