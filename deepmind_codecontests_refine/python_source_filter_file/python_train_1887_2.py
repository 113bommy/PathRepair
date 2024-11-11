import sys
import math
from collections import defaultdict,deque
n=int(sys.stdin.readline())
dic=defaultdict(int)
arr=list(map(int,sys.stdin.readline().split()))
for i in range(n):
    dic[arr[i]]+=1
#print(dic)
l=[]
for i in dic:
    l.append(dic[i])
l.sort()
two=[]
num=1
i=0
m=len(l)
count=0
ans=0
for i in range(1,l[-1]+1):
    pos=len(l)-1
    cur=i
    res=cur
    while cur%2==0 and pos>0:
        cur/=2
        pos-=1
        if l[pos]<cur:
            break
        res+=cur
    ans=max(ans,res)
print(ans)
