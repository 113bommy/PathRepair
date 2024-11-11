__author__ = 'Utena'
import operator
n,m=map(int,input().split())
s=list(map(int,input().split()))
r0=[[0,10000000000]]
x0=[0]
for i in range(m):
    t,r=map(int,input().split())
    while r>=r0[-1][1]:
            r0=r0[:-1]
            x0=x0[:-1]
    r0.append([t,r])
    x0.append(i)
Q=sorted(s[:r0[1][1]])
r0.append([0,0])
x=0
j=2
y=r0[1][1]-1
i=r0[1][1]-1
while True:
    while i>=r0[j][1]:
        if r0[j-1][0]==2:
            temp=Q[x]
            x+=1
        else:
            temp=Q[y]
            y-=1
        s[i]=temp
        i-=1
        if i<0:break
    j+=1
    if y<x:break
print(' '.join(map(str,s)))