#code
import sys
import math as mt
#input=sys.stdin.buffer.readline
#t=int(input())
#tot=0
t=1

def getZarr(string, z): 
	n = len(string) 

	# [L,R] make a window which matches 
	# with prefix of s 
	l, r, k = 0, 0, 0
	for i in range(1, n): 

		# if i>R nothing matches so we will calculate. 
		# Z[i] using naive way. 
		if i > r: 
			l, r = i, i 

			# R-L = 0 in starting, so it will start 
			# checking from 0'th index. For example, 
			# for "ababab" and i = 1, the value of R 
			# remains 0 and Z[i] becomes 0. For string 
			# "aaaaaa" and i = 1, Z[i] and R become 5 
			while r < n and string[r - l] == string[r]: 
				r += 1
			z[i] = r - l 
			r -= 1
		else: 

			# k = i-L so k corresponds to number which 
			# matches in [L,R] interval. 
			k = i - l 

			# if Z[k] is less than remaining interval 
			# then Z[i] will be equal to Z[k]. 
			# For example, str = "ababab", i = 3, R = 5 
			# and L = 2 
			if z[k] < r - i + 1: 
				z[i] = z[k] 

			# For example str = "aaaaaa" and i = 2, 
			# R is 5, L is 0 
			else: 

				# else start from R and check manually 
				l = i 
				while r < n and string[r - l] == string[r]: 
					r += 1
				z[i] = r - l 
				r -= 1

for __ in range(t):
    #n=int(input())      
    #l=list(map(int,input().split()))  
    #n,m=map(int,input().split())            
    #l=list(map(int,input().split()))
    s=input()
    z=[0]*(len(s)+1)
    d={}

    n=len(s)    
    getZarr(s, z)
    #print(z)
    d=[]
    maxm=-1
    for i in range(len(s)):
        if i+z[i]!=n:
            maxm=max(maxm,z[i])
        else:
            d.append(z[i])
    maxi=-1
    d.sort()
    for i in range(len(s)):
        if i+z[i]==n:
            if maxm>=z[i]:
                maxi=max(maxi,maxm)
            if d[-1]!=z[i]:
                maxi=max(maxi,z[i])
    if maxi>0:
        print(s[:maxi])
    else:
        print("Just a legend")
            
                
            