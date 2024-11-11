t=int(input())
for i in range(t):
    n=0
    x=0
    num=int(input())
    while n<=num:
        x=x+1
        m=(2**x)-1
        n+=(m*(m+1))/2
    print(x-1)