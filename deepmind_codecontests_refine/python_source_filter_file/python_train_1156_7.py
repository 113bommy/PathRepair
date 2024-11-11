from collections import defaultdict as dif 
dic=dif(lambda:0)
x=int(input())
if x==1:
    print(0,0)
    exit(0)

while x%2==0:
    dic[2]+=1
    x//=2

mx=dic[2]

n=3
while n*n<=x:
    while x%n==0:
        dic[n]+=1
        x//=n
    mx=max(mx,dic[n])
    n+=2
if x>1:
    dic[x]=1
    mx=max(1,mx)
from math import log2,ceil
lg =ceil(log2(mx))
mxt=1<<lg
nm=1
stp=0
for n in dic:
    if dic[n]!=mxt and dic[n]:
        stp=1
        break


for n in dic:
    if dic[n]:
        nm*=n

stp+=lg
print(nm,stp)