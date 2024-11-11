from fractions import gcd
a,b=map(int,input().split())
d=max(a,b)-min(a,b)
c=[float("inf"),1]
e=[]
for i in range(1,int(d**0.5)+1):
    if i**2==d:
        e.append(i)
    elif d%i==0:
        e.append(i)
        e.append(d//i)
for i in e:
    h=i*((a-1)//i+1)-a
    if c[0]>((a+h)*(b+h)//gcd(a+h,b+h)):
        c[0]=(a+h)*(b+h)//gcd(a+h,b+h)
        c[1]=h
print(c[1])