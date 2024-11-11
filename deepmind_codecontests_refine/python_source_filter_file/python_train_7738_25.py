from collections import defaultdict as di 
import copy
import math
no=(10**5)+3
sieve=[1]*(no)
sieve[0]=0
sieve[1]=0
i=2

while(i*i<no):
    if sieve[i]==1:
        j=i
        while(i*j<no):
            sieve[i*j]=0
            j+=1
    i+=1
#c=0
def solve(n,k):
    c=0
    z=[]
    for i  in range(1,n+1):
        if sieve[i]:
            z.append(i)
    i=2
    #print(z)
    while(i+1<len(z) and (z[i]+z[i+1]+1)<n):
        if sieve[z[i]+z[i+1]+1]:
            #print(z[i]+z[i+1]+1)
            c+=1
        i+=1

    if c>=k:
        return True
    else:
        return False
    
n,k=map(int,input().split())
if solve(n,k):
    print('YES')
else:
    print('NO')



