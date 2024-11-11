from math import sqrt
a,b=map(int,input().split())
c=a+b;
sa=int(sqrt(a))
sb=int(sqrt(b))
sc=int(sqrt(c))
#print(a,b,c,sa,sb,sc)
m=c
ans=0

for i in range(1,sc+1):
    if i<=sa and a%i==0:
        m=min(m,a//i)
    if i<=sb and b%i==0:
        m=min(m,b/i)
    if c%i==0:
        tmp=c/i
        if tmp>=m:
            ans=(i+tmp)*2

print(int(ans))