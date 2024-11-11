import math 
n,k=map(int,input().split())
s=list(input())
s=[int(s[i]) for i in range(n)]
b=[0]*n
for i in range(k):
    b[i]=s[i]
for i in range(k,n):
    b[i]=b[i-k]
if b<s:
    i=k-1
    while(b[i]==9):
        b[i]=0
        i-=1 
    b[i]+=1
    for i in range(k,n):
        b[i]=b[i-k]
print(n)
print(*b,sep="")
    