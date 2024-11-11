import sys
import math
from collections import Counter
from collections import OrderedDict
sys.setrecursionlimit(10**6)
def inputt():
    return sys.stdin.readline().strip()
def printt(n):
    sys.stdout.write(str(n)+'\n')
def listt():
    return [int(i) for i in inputt().split()]
 
def gcd(a,b): 
   return math.gcd(a,b) 
 
def lcm(a,b): 
    return (a*b) // gcd(a,b) 

def string(l,li,n,k):

    if n==0 or k==0:
        return 0
    else:
        if l[n-1]==li[k-1]:
            return 1+string(l,li,n-1,k-1)
        else:
            return (string(l,li,n-1,k)+string(l,li,n,k-1))



n,k=map(int,inputt().split())
sreal=inputt()
s=inputt().split()
li=[]
for i in sreal:
    if i in s:
        li.append(1)
    else:
        li.append(0)
count=0
ans=[] 
for i in range(1,n):
    if li[i]==1:
        count+=1
    else:
        ans.append(count)
        count=0  
    if i==(n-1):
        ans.append(count)    
jelo=0          
for i in ans:
    jelo+=i*(i+1)//2
print(jelo)    






