# Prime number sequence
This program store prime number up to n using bit vector and determine if they are palindrome, lucas, fabonacci or mersenne.

## DESIGN.pdf
- Answered all pre lab questoins.
- Flow chart of the program
- Fully explained the design of the program.
- Explain how bit vector works

## Sequence.c
### main
- - take arguement from the command prompt
- if we invalid arguement inputted, error message will be displayed
- edited the switch function from last assignment
- For option, I put ":spn:" so the program won't require user to input an arguement everytime after -n
- The function only stores a bool variable and the stack and recursive function only be called after the switch function.
- call stack_delete at the end to deallocate the memory of the stacks created.
## -s
- Set up a function call print_prime()
- The function loop through all primes within 0-n using bv_get_bit()
- If the number is prime, print_print() calls fabonacci(), lucas() and mersenne()
- Those three functions prints out their name if they determine the number is their own type
### fabonacci( int prime)
- Determine whether this prime is fabonacci
- Given the first two term of fabonacci
- The function iterates untill it reaches the next fabonacci is larger than the given prime
### lucas( int prime)
- Determine whether this prime is lucas
- Given the first two term of lucas
- The function iterates untill it reaches the next lucas is larger than the given prime
### mersenne( int prime)
- Determine whether this prime is mersenne
- Uses the formula of getting mersenee
- Use loop to find the nth term
- The function iterates untill it reaches the next mersenne is larger than the given prime
## -p
- Check four bases 2, 9, 10, 21(K)
- A for loop for each base, base() function is called instead the loop
- Only loop through all prime, the call the base() function
### base(int base, int prime)
- The function determine whether this number is palindrome
- First convert the number to another base in string.
- Dynamically allocates memory string
- Deallocate memory at the end of the function
- Use two pointer approach to check whether the string is palindrome
## bv.c
- Uses bit vector to store boolean value of whether the number is prime
- each byte can store up the 8 number becasue the arrary is 8 bit
- use bit mask to alter the value 
- Determine how many byte we need to allocate by doing length/8+1
- No memory leaks determined by valgrind.
- Make infer gave me error message but I assume its a known bug of make infer because it doesn't seem to know that I free my memory in main.
## sieve.c
- copied from the lab
