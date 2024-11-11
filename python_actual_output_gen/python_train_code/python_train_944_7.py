# coding: utf-8
# Your code here!
n,a,b=map(int,input().split())
h=[]
for i in range(n):
    x=int(input())
    h.append(x)

def check(t):
    c=0
    for i in range(n):
        c+=1+(max(0,h[i]-b*t)-1)//(a-b)
    return t>=c

l=0
r=1+max(h)//b
while r-l>1:
    mid=(r-l)//2+l
    if check(mid):
        r=mid
    else:
        l=mid
ans=l
if check(r):
    0#ans=r
print(ans)

