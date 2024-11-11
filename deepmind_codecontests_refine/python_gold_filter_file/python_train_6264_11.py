x=int(input())
a=list(map(int,input().split()))
b=max(a)
c=a.index(b)
d=c-1
if c<x:
    c+=1
f=0
while c<x:
    if a[c]>a[c-1]:
        f=1
        break
    c+=1
while d>=0:
    if a[d]>a[d+1]:
        f=1
        break
    d-=1    
if f==0:
    print("YES")
else:
    print("NO")