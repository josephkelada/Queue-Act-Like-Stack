# Queue-Act-Like-Stack
To Run the project you can either execute the exe file in the debug folder(stack with queue\ConsoleApplication3\Debug) or simply open the solution in Visual Studio And run it from there
This simple project is a small algorithm that makes a queue act like a stack by changing the functionality of the core functions of a queue
so basically how it works is :
we want 2 queues to act like a stack theoretically.
so we want to be able to generate a top() method and that method will give us the last number entered by the user.
the pop() method should remove the first one.


everytime push() gets called we want it to store the element given next to the last element(to the left).

so we have 2 queues ,
we want 1 queue to hold the real order of the stack at the end of each push() call and during the entire runtime.

queue 2 is the temporary hold for the elements and queue 1 is the permanent one.

the showQueue() function in the Stack class actually returns the top() of the queue every iteration of the loop which also calls pop()
