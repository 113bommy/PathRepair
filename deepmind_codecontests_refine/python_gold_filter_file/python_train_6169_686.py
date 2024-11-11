import math 
import sys

sys.setrecursionlimit(10**4) 

def Divisors(n) : 
	
	l=[]
	i = 2
	while i <= math.sqrt(n): 
		
		if (n % i == 0) : 
			
			
			if (n // i == i) : 
				l.append(i)
			else : 
				l.append(i)
				l.append(n//i)
		i = i + 1
	return l

def SieveOfEratosthenes(n): 
	
	l=[]
	
	prime = [True for i in range(n+1)] 
	p = 2
	while (p * p <= n): 
		
		if (prime[p] == True): 
			
			for i in range(p * p, n+1, p): 
				prime[i] = False
		p += 1
	
	for p in range(2, n+1): 
		if prime[p]: 
			l.append(p)
	
	return l		

def primeFactors(n): 
	
	l=[]
	
	while n % 2 == 0: 
		l.append(2) 
		n = n / 2
		
	for i in range(3,int(math.sqrt(n))+1,2): 
		
		while n % i== 0: 
			l.append(i) 
			n = n / i 
			
	if n > 2: 
		l.append(n)
	
	return(l)	
		

def Factors(n) : 
	
	
	result = []
	
	for i in range(2,(int)(math.sqrt(n))+1) : 

		if (n % i == 0) : 
		    
			if (i == (n/i)) : 
				result.append(i)
			else : 
			    result.append(i)
			    result.append(n//i)
		
	result.append(1)
	result.append(n)
	return result

def maxSubArraySum(a): 
	
	max_so_far = 0
	max_ending_here = 0
	size=len(a)
	
	for i in range(0, size): 
		max_ending_here = max_ending_here + a[i] 
		if (max_so_far < max_ending_here): 
			max_so_far = max_ending_here 

		if max_ending_here < 0: 
			max_ending_here = 0
	return max_so_far 

def longestsubarray(arr, n, k): 
    current_count = 0
      
    # this will contain length of  
    # longest subarray found 
    max_count = 0
  
    for i in range(0, n, 1): 
        if (arr[i] % k != 0): 
            current_count += 1
        else: 
            current_count = 0
        max_count = max(current_count,  
                            max_count) 
      
    return max_count 
    
#print(SieveOfEratosthenes(100))
#print(Divisors(100))
#print(primeFactors(100))
#print(Factors(100))
#print(maxSubArraySum(a)

def main():

    n=int(input())
    #n,k=list(map(int,input().split()))
    #l=list(map(int,input().split()))
               
    if(n%4==0):
        print("YES")
    else:
        print("NO")
    
            
t=int(input())
for i in range(0,t):
    main()


    