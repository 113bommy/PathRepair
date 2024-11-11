a=int(input())
b=int(input())
c=int(input())
d=int(input())
m=a*2+b+c
n=d*2+b+c
if a==0 and d==0 and c!=0:
    print(0)
elif m==n:
    print(1)
else:
    print(0)