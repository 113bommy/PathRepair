import sys
import os.path
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt','r')
    sys.output = open('output.txt','w')
n=int(input())
l=list(map(int,input().split()))
neg=[0]*(n)
pos=[0]*(n)
if l[0]>=0:
    pos[0]=1
for i in range(1,n):
    if l[i]>=0:
        pos[i]=pos[i-1]+1
    else:
        pos[i]=pos[i-1]
if l[-1]<=0:
    neg[-1]=1
for i in range(n-2,-1,-1):
    if l[i]<=0:
        neg[i]=neg[i+1]+1
    else:
        neg[i]=neg[i+1]
ans=float("inf")
#print(pos)
#print(neg)
for i in range(n-1):
    ans=min(ans,pos[i]+neg[i+1])
print(ans)