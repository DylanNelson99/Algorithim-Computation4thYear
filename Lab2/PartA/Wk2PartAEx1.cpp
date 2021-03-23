//Dylan Nelson - X00144862
//Answer to how the results above were produced

/* Documentation for the code and how the results above were produced.
-> We have three pointer variables created from the type of definition declaration to allow us to use that variable as a type for these pointers : a, band c.
-> We declared a and b to store the memory address of two arrays.
-> Declaring i to use as a counter for the for loops.
-> Within the first for loop we set the size of it as a numeric value or we could use the sizeof() function to get the size of the array instead.
-> The loop will then iterate until i > 3. On each iteration, we store the value in each element of the array.As you can see, the values for the array i are going to be[0, 1, 2] and for be, it will be[0, 100, 200] as i is being multiplied by 100.
-> Next, we have a code like this c = a; This means that c is now pointing to whatever a is pointing to as well, which the array of ints with the values[0, 1, 2].
-> Next, every one of the arrays are printed outand we could see that aand c have the same content compared to b.
-> Calling the swapValues() function and passing both a and b, swap the arrays around.

-> template < typename T>
void swapValues(T & variable1, T & variable2)
{
	T temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

->Here is the swap function in code.This is not your normal function with a fixed data type but instead we used a template function.These functions are functions that can handle generic types, with whatever you pass in or deal with.
->The prefix on line 12 is an important thing to have as you are declaring that you want this function to be a template.Within the parameters of the function, we have two generic types that are being passed in by reference address 
 that points to the actual arrays in the main program.
->On line 15 we have another generic type named temp, where it stores the reference address of variable1and variable1 now has the address of variable2.Upon completion of this function, variable1(a), should now be pointing to(b) and 
 variable2(b), should now be pointing to(a).

-> b[0] = 42;

->Here we are just overriding the value on the first element of the array with the value of 42.

-> cout << "a contains: ";
for (i = 0; i < 3; i++)
	cout << a[i] << " ";
cout << endl;
cout << "b contains: ";
for (i = 0; i < 3; i++)
	cout << b[i] << " ";
cout << endl;
cout << "c contains: ";
for (i = 0; i < 3; i++)
	cout << c[i] << " ";
cout << endl;

->Then we print all the arrays again to see the final output result.

-> a contains : 0 100 200
b contains : 42 1 2
c contains : 42 1 2

-> We can see that this result is the same result above, and we can see that a has the contents of b.b has a different content as the first element was overrideand since b is pointing to the original content of a, that means that c should have 
 the same content as b because c points to a. */
