n,p=map(int,input().split())
from sys import stdin
s=stdin.readline().rstrip('\n')
l=[0]*n
for i in range(n//2):
    if s[i]!=s[n-1-i]:
        a=abs(ord(s[i])-ord(s[n-1-i]))
        b=ord(s[i])-97+1+122-ord(s[n-1-i])
        c=ord(s[n-1-i])-97+1+122-ord(s[i])
        l[i]=l[n-1-i]=min(a,b,c)
c=0
for i in range(n//2):
    c+=l[i]
p=p-1
if p>n//2:
    p=n-1-p
if c!=0:
    a=0
    for i in range(n//2-1,p,-1):
        if l[i]!=0:
            a=i-p
            break
    b=2*a
    d=0
    for i in range(p):
        if l[i]!=0:
            d=p-i
            break
    b+=d
    a+=2*d
    print(min(a,b)+c)
else:
    print(0)


        
