import math
a,b,c,d=list(map(int,input().split()))
if c/d>a/b:
    p=b*c-a*d
    q=b*c
else:
    p=a*d-b*c
    q=a*d
for i in range(2,p):
    if p%i==0 and q%i==0:
        while p%i==0 and q%i==0:
            p=p//i
            q=q//i
if p==0:
    q=1
print(str(p)+'/'+str(q))