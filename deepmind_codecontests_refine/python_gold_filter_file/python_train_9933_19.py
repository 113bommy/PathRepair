from collections import defaultdict
from sys import stdin, stdout  
n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=sum(a[:k])
val=ans 
start=1
for i in range(1,n-k+1):
    val+=a[i+k-1]
    val-=a[i-1]
    if(val<ans):
        ans=val
        start=i+1
print(start)
