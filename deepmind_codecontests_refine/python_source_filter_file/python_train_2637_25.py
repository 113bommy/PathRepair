from math import ceil
n=int(input())
s=[int(i) for i in input().split()]
a,b,c,d=0,0,0,0
for j in range(n):
    if s[j]==1:
        a+=1
    if s[j]==2:
        b+=1
    if s[j]==3:
        c+=1
    if s[j]==4:
        d+=1
#print(a,b,c,d)
x=0
x+=d
d=0
if c<=a:
    x+=c
    a=a-c
    c=0
else:
    x+=c
    a=0
    c=0
if b%2==0:
    x+=b/2
    b=0
else:
    if a!=0:
        x+=(b+1)/2
        a-=2
        if a!=0:
            x+=ceil(a/4)
            a=0
    else:
        x+=ceil(b/2)
if a!=0:
    x+=a/4
print(int(x))
            
    
