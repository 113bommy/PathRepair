# coding: utf-8
# Your code here!

m= int(input())
dc=[]
s=0
for i in range(m):
    dc.append(list(map(int,input().split())))
    s+=dc[i][0]*dc[i][1]

print(s)

ans=s//9

for i in range(m):
    ans+=dc[i][1]

if s%9==0:
    ans-=1

print(ans-1)
