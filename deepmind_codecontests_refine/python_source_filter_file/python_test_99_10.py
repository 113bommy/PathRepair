
t=int(input())

for _ in range(t):
    x,n=map(int,input().split())
    p = (n+1)//2

    if n%4==1:
        d = 1+n//4
    elif n%4==0:
        d = 0
    elif n%4==2:
        d=-1
    else:
        d = - (n+1)

    if x%2==0:
        print(x-d)
    else:
        print(x+d)
