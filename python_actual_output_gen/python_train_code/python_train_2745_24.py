x,y=map(int,input().split())
m=10**9+7
if (2*x-y)%3==0 and (2*y-x)%3==0 and 2*x-y>0 and 2*y-x>0:
    a,b=(2*x-y)//3,(2*y-x)//3
    c=min(a,b)
    p=1
    for i in range(c):
        p=(p*(a+b-i)*pow(i+1,m-2,m))%m
    print(p)
else:
    print(0)