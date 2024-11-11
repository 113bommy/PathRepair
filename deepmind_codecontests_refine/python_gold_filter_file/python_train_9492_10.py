import sys
import math
input=sys.stdin.readline
def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)
def factors(g):
    f=0
    i=1
    while(i<=math.sqrt(g)):
        if(g%i==0):
            if(i==g//i):
                f+=1
            else:
                f+=2
        i+=1
    return f
n=int(input())
arr=list(map(int,input().split()))
g=arr[0]
for i in range(n):
    g=gcd(g,arr[i])
print(factors(g))

    
        
    
    
