

Number | Type (BUG/Just Bad) | Error | Commentary
--- | --- | --- | ---
1| BUG| Running the program without any command line args causes the program to seg fault | Potential fix shown in code
2| BUG | The program instructs you to type 'y' to continue. If you do so, the program stops executing, so either the text or the behavior is wrong| TODO
3| BUG | Using 'gets' is unsafe - it jsut points to a memory address and is prone to all sorts of errors| Use fgets instead (see code)
4 | Just bad | Why is the address of the answer being printed? | No one cares about that
5 | BUG | Should only do comparison against string literals as variables, not inputs | Unsecure - use single quotes instead
6 | Just bad | If the user did not input an interger in argv[1], this is not going to behave as expected | Consider parsing input [Check if input is integer type in C - Stack Overflow](https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c). (For the purposes of this assignment, we'll just assume a valid int has been entered from this point on.)