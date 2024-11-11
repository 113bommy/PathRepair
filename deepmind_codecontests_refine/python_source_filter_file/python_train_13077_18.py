import math
m=1
a,b=map(int,input().split())
if(((b%10>=5 or b%10==0) and b-a>=1 and a%10<5) or b-a>=9):
    print(0)
elif(a==b):
    print(1)
else:
    for i in range(b,a,-1):
        m=m*(i%10)
        m%=10
    print(m)