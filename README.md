# Digital_Clock
-----------------------
# Program explanation
This project allows the user to create a digital clock that displays both a 
12-hour clock and 24-hour clock. The console can be interacted with to access 
a menu to increment the time setting to the local time. The menu also has an 
option to terminate the program.

# What was done well
The menu properly utilizes Windows library methods to actively record user input 
as to not interrupt the count of the clock. The clock face is accurately displayed 
and counted by one second for every second in real world time. The clock design 
offers an easily legible interface with a simple input system.

# Future expansions
A needed addiion is a method to de-increment the time as leniency for mistakenly 
over-incrementing to the desired time. A future expansion upon this time control 
could be the ability to automatically syncronize with the local time listed from 
an active clock website. Future additions could include a customizable display 
face for the clock or even further Windows integration for a customizable clock 
overlay, similar to the popular Rainmeter software.

# Areas of struggle
One solution that prevented me from completing the project is being unaware of 
the active user input recording offered from the Windows library. I had no way 
for the clock to continue to tick without having the user input to continue the 
loop when recording if there was a keystroke to enter into the menu using the 
iostream library, but the Windows library solved this issue by offering the  
function necessary to complete this process.

# Lessons
I gathered a fundamental understanding of utilizing external libraries to accomplish 
the task without the need of implementing my own solution. This approach allowed me 
to save time when developing my skills in the concerned areas than to become barred 
by not understanding how a complex function, like the one offered from the Windows 
library, worked well enough to allow me to develop my own solution.

# Industry Standards
I included numerous comments on most execution lines that explain the code 
and why the process was implemented. The most important aspect when developing 
a program is being able to return in the future and easily understand what 
the program is doing and why each line is executing to achieve this goal.
Without a legible reference for the future individual, there is no guide 
to understanding how or why the process functions in the chosen method, 
since every individual will have a different solution to the same problem
based on their background and relevant experience.
