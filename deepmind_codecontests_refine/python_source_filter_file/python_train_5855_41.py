# Python program to print prime factors 
ans=[]
import math 

# A function to print all prime factors of 
# a given number n 
def primeFactors(n): 
	
	# Print the number of two's that divide n 
	while n % 2 == 0: 
		ans.append(2)
		n = n / 2
		
	# n must be odd at this point 
	# so a skip of 2 ( i = i + 2) can be used 
	for i in range(3, int(math.sqrt(n))+1, 2): 
		
		# while i divides n, print i ad divide n 
		while n % i == 0: 
			ans.append(i)
			n = n // i 
			
	# Condition if n is a prime 
	# number greater than 2 
	if n > 2: 
		ans.append(n)
		
# Driver Program to test above functio
n=int(input())
primeFactors(n) 
a=""
for i in range(len(ans)):
    a+=str(ans[i])
print(a)

# This code is contributed by Harshit Agrawal 
