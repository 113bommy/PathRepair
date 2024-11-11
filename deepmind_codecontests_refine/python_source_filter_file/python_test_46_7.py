# cook your dish here
import math
def modInverse(p, q):
	
	    mod = 998244353
	    expo = 0
	    expo = mod - 2

	    # Loop to find the value
	    # until the expo is not zero
	    while (expo):
	        if (expo & 1):
	            p = (p * q) % mod
	        q = (q * q) % mod
	        expo >>= 1
	    return p
	    
def answer(x,y,li):
    s=[]
    for p in range(0,len(li)-1):
        s.append(li[p+1]-li[p])
    s.append(int(1e18))
    
    def solu(s,fi,y):
        m=0
        for j in range(0,len(s)):
            m=m+min(s[j],fi)
        return(m>=y)
        
    low=1
    high=int(1e18)
    ans=0
    while (low<high):
        fi=(low+high)//2
        if solu(s,fi,y):
            high=fi
            ans=fi
        else:
            low=fi+1
    
    return ans
    
    
t=int(input())
for i in range (0,t):
    x=int(input())
    s=input()
    r=-1;m=0
    for x in map(int,s.split()[::-1]):
        print(x)
        if x>m:
            r+=1
            m=x
    print(r)
