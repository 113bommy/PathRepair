import sys
import math
from collections import defaultdict
n=int(sys.stdin.readline())
integer=[False for _ in range(n)]
arr1,arr2=[],[]
for _ in range(n):
    a=float(sys.stdin.readline()[:-1])
    if a%1==0:
        arr1.append(a)
        arr2.append(a)
        integer[_]=True
    else:
        c,d=math.floor(a),math.ceil(a)
        if a<0:
            arr1.append(d)
            arr2.append(c)
        else:
            arr1.append(d)
            arr2.append(c)
#print(arr1,'arr1')
#print(arr2,'arr2')
s=sum(arr1)
#print(s,'s')
i=0
ans=[]
while s>0:
    if integer[i]==False:
        ans.append(arr2[i])
        s-=1
        i+=1
    else:
        ans.append(arr1[i])
        i+=1
for j in range(i,n):
    ans.append(arr1[j])
for i in range(n):
    print(int(ans[i]))
