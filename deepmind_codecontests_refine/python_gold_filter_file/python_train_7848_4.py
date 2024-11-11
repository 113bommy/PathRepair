import math
t=int(input())
l=list(map(int,input().split()))
l.sort()
s=sum(l)
a=s
j=1
m=0
for i in l:
    s-=i
    m+=s-(t-j)*i
    j+=1
x=2*m+a
y=math.gcd(x,t)
x//=y
t//=y
print(x,t)