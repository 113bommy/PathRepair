import math
from decimal import *
import random

n = int(input())
arr = list(map(int, input().split()))
add = 0
sub = 0
if(n%2==1):
    add+=1
if(n%2==0):
    sub+=1
pnt1, pnt2 = 0,0
a1, a2 = arr[int(math.ceil(n/2))-add:], arr[:n//2]
ans = []
pos = True
for i in range(n):
    if(pos):
        ans.append(str(a1[pnt1]))
        pos= False
        pnt1+=1
    elif(not pos):
        ans.append(str(a2[pnt2]))
        pos = True
        pnt2+=1
print(n//2-sub)
print(' '.join(ans))
