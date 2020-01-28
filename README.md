# Basic-Airport-Scheduling-Simulator
To build a Scheduling Simulator which would deal with day to day scheduling schema of an Airport.
Our Simulator consists of an inbuilt mechanism which allocates the process, in this case the airport. It allocates Length, Order, and Priority using all the scheduling algorithms, primarily FCFS, SJF and Priority. For Example, we have several aeroplanes at an airport waiting for transportation. We have to allocate them with specific time, order and duration of their flight. Think about it ...For Example- We have Shortest Job First (SJF) Scheduling Algorithm as the user(passenger) chooses the flight which has the least flight time and is nearer to the destination. We basically intend to create a User-Aeroplane Simulator in which user gets to choose his aeroplane according to the preference i.e. least flight time, a flight which has a drop point at his destination or which is closer to his destination.
We even have to allocate a flight with a pilot in an airport. There are many pilots in an Airport and they may fly more than one plane. So, we have to allocate a pilot who is free. i.e. waiting. Our Simulator will choose the best pilot out of the given inputs and allocates it to the flight. Our Simulator simultaneously uses all the scheduling algorithms and allocates the user with suitable aeroplane with flight Time, destination, a suitable pilot for the flight and a feasible schedule. We even have to remove the aberrations like we cannot allocate two planes at the same time to a single user even if they are free. Similarly, we cannot allocate two pilots at the same time. We have to automatically allocate the best possible for the user. Sometimes we even have to use two flights for a single journey if the distance is large.
So, the simulator uses the permutations and provides two flights. As we know we cannot keep the other flights waiting while one flight is in action. So, this simulator automatically assigns the other free airplanes to their suitable users. The Simulator has to remove such errors like when a flight is in action, the other flight can’t be kept waiting. Even this flight has to be given a burst time simultaneously. We have to implement multi-process scheduling mechanism for this purpose.
The objectives of this project includes minimization of work for airline personnel and minimization of airplane delays.
