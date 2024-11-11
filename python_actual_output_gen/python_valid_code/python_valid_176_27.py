x,y=map(int,input().split())
n=int(input())
z=y-x
if n%3==1:
    print((((-1)**(n/3))*x)%(10**9+7))
elif n%3==2:
    print((((-1)**(n/3))*y)%(10**9+7))
elif n%3==0:
    print((((-1)**(n/3+1))*z)%(10**9+7))