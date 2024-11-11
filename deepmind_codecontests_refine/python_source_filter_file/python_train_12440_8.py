import math
from collections import Counter,defaultdict
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
n=I()
a=LI()
for i in range(n):
    while a[i]%2==0:a[i]//=2
    while a[i]%3==0:a[i]//=3
flag=1
print(a)
for i in range(n-1):
    if a[i]!=a[i+1]:flag=0;break
if flag:print("Yes")
else:print("No")




    

            







        
