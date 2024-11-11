from sys import stdin
from collections import Counter as c
gh=1000000000;k=1;p=[]
while k<=gh:k*=2;p+=[k]
a=int(stdin.readline())
b=list(map(int,stdin.readline().split()))
d=c(b);s=0
for i in range(a):
    for j in p:
        if 2*b[i]==j:
            if d[b[i]]>1:s+=1;break
        elif d[j-b[i]]!=0:s+=1;break
print(a-s)
