import math 

def Divisors(n) : 
	
	l=[]
	i = 1
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

#print(SieveOfEratosthenes(100))
#print(Divisors(100))
#print(primeFactors(100))
#print(Factors(100))
#print(maxSubArraySum(a)
def main():

    l1=[]
    for j in range(0,1025):
        l1.append(0)
    n=int(input())
    l=list(map(int,input().split()))
    x=0
    
    if n%2 == 1:
        print(-1)
        
    else:    
        for j in l:
            l1[j]=1
        for j in range(1,1024):
            f=0
            for k in range(0,n):
                if l1[l[k]^j]==0:
                    f=1
                    break
            if f==0:
                print(j)
                break
        if f==1:
            print(-1)
            
        
t=int(input())
for i in range(0,t):
    main()


    