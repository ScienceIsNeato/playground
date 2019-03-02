This markdown file describes the various issues found with the code. Open in a markdown editor (i.e. [Dillinger](https://dillinger.io/), [Boostnote](https://boostnote.io/), etc.) for pretty formatting.

References found in code in format /* See Note X */

Number | Type (BUG/Just Bad) | Error | Commentary
--- | --- | --- | ---
1| BUG| Running the program without any command line args causes the program to seg fault | Potential fix shown in code
2| BUG | The program instructs you to type 'y' to continue. If you do so, the program stops executing, so either the text or the behavior is wrong| Fixed in code
3| BUG | Using 'gets' is unsafe - it jsut points to a memory address and is prone to all sorts of errors| Use fgets instead (see code)
4 | Just bad | Why is the address of the answer being printed? | No one cares about that
5 | BUG | Should only do comparison against string literals as variables, not inputs | Not secure - use single quotes instead
6 | Just bad | If the user did not input an integer in argv[1], this is not going to behave as expected | Consider parsing input [Check if input is integer type in C - Stack Overflow](https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c). (For the purposes of this assignment, we'll just assume a valid int has been entered from this point on.)
7 | Just bad approaching BUG | poor code placement and memory management | no reason to malloc an int - it is a built in, fixed width data type. Also, don't initialize in the while loop |
8 | BUG and Just bad | Weird function signature | getters typically return something. Getters typically only accept input if necessary to function. Very odd to pass in a void reference instead of a void pointer - will cause errors |
9 | Just bad | unnecessarily verbose | no need to initialize and then return when you can use a one liner |
10 | Just bad | should print this as string literal - modified code | potentially insecure
11 | BUG/Just Bad | wrong input param type | method name says 'get string from int' but passing in a long
12 | Just Bad | Made an improvement for stability/memory resources | The string that holds the int conversion could need 6 to 11 characters. These lines minimize the amount of memory required. Note it isn't perfect (you prefer to do the malloc'ing and free'ing in the same method when possible)
13| Just bad | memory leak | should free the memory used to temporarily house the numeric string on each loop iteration (note - malloc'd elsewhere; that happens sometimes)
14| BUG | file doesn't open | missing the '\| O_CREATE' line to create the file if missing. Also, permissions were a bit open - no need to make the file executable |
15 | BUG | No error handling | in this method, there isn't any error handling for failure to open file or failure to write to file|
16 | Just bad | not SOLID | a method called 'write_string_to_file' should probably recieve a file descriptor in its input args and return an int or bool to indicate success. The calling function should exit main with the appropriate error code in case of failure to write. Code outside of the method should handle failure to open file handle. None of that is happening.|
17 | BUG | incorrect decrementer | putting \-\- in front of variable executes decrementation before evaluation, which has the effect of creating one fewer number than intended |
18 | BUG | possible memory corruption | 32 bytes is enough for 'output.txt', but not full paths. Using PATH_MAX is pretty safe for most cases |
19 | Just bad | numbers just pseudorandom | using rand without first calling srand means that the same random numbers get generated each time you run the program. |
20 | Just bad | poor description | very weak program description. No header with author, date, etc. No copyright info. Even basic explanation of what program does is vague - does it write each random number and then an md5sum to the file? Is it supposed to append to an existing file, or open new at program start? We'll assume always append and always just write md5sum to the file at the end of the program (just once) because that seems most sensical, I suppose?|
21 | Just bad | method name doesn't describe behavior | a more accurate name is printMd5sum, since that's what it does|
22| BUG (maybe) | the command provided doesn't work on a mac | should probably check system architecture
23 | Just bad | poorly formed system call | the output on a mac of md5 includes the filename and some punctuation - gotta suppress with -q. Then there's some newlines and such in there. No idea what author had intended so took a stab. Likely need to do similar stuff in linux depending on intended output|
24 | Just Bad | no error checking | should warn user if md5 command failed |
25 | Just Bad | method too long | main is too long. Should be broken out into methods (i.e. 'initialize' 'parseUserInput', etc.)
26 | Just bad | general problem with 'output.txt' | that string is hardcoded in multiple places throughout the code. Would probably be better to be passed in from command line and stored as a variable (could have 'output.txt' be default val if no output file provided though) |
27 | Just bad | don't just return 0 | Should return 0 if success, error code otherwise - other programs might depend on that!
28| BUG | not closing fd | if you don't close on each loop iteration, you quickly run out of file handles |