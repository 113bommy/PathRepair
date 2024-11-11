import math
a,b=map(int,input().split())
while b!=0:
    a,b=b,a%b
c=a
d=[]
for i in range(2,int(c**0.5)+2):
    while c%i==0:
        c//=i
        d.append(i)
if c!=1:
    d.append(c)
print(d)
print(len(set(d))+1)