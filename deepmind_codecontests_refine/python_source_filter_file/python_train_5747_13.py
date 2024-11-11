import math
from collections import Counter,defaultdict
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
def prime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
def fact(n):
    s=[];j=2
    while j*j<=n:
        if n%j==0:
            s+=[j]
            while n%j==0:n//=j
        j+=1
    if n>1:s+=[n]
    return s
n=I()
if prime(n):
    print(n)
else:
    s=fact(n)
    if len(s)==1:
        print((n+1)//s[0])
    else:
        print(1)






        
        
            


        



    









    

            







        
