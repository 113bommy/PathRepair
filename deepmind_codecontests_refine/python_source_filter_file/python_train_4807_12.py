import math
from collections import Counter,defaultdict
I =lambda:int(input())
M =lambda:map(int,input().split())
LI=lambda:list(map(int,input().split()))
n=I()
a=LI()
a.sort()
temp=a[-1];a[-1]=a[-2];a[-2]=temp
if a[-1]<a[-2]+a[0]:
    print("YES")
    print(*a)
else:
    print("NO")





    

            







        
