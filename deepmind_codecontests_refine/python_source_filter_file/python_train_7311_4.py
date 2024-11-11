import sys
import math
input=sys.stdin.buffer.readline
#t=int(input())
mod=998244353
# Python3 function to 
# calculate nCr % p 
def ncr(n, r, p): 
	# initialize numerator 
	# and denominator 
	num = den = 1
	for i in range(r): 
		num = (num * (n - i)) % p 
		den = (den * (i + 1)) % p 
	return (num * pow(den, 
			p - 2, p)) % p 

t=1
for _ in range(t):
    n=int(input())
    #n,k=map(int,input().split())
    l=list(map(int,input().split()))
    pref=[0]*(n+1)
    pref[0]=l[0]
    d={}
    lef=-1
    ans=0
    for i in range(n):
        if l[i]==0:
            lef=i+1
        if i!=0:
            pref[i]=pref[i-1]+l[i]  
        if d.get(abs(pref[i]),-1)==-1:
            d[abs(pref[i])]=[]
           
        if len(d[abs(pref[i])])>=1:
            lef=max(lef,d[abs(pref[i])][-1]+1)
        d[abs(pref[i])].append(i) 
        if pref[i]==0:
            lef=max(lef,0)
        #print(d)  
        ans+=(i-lef)
        #print(i,ans,lef)
        
    print(ans)    