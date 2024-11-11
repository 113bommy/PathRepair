t=int(input())
for i in range(t):
    n=int(input())
    sum=n*(n+1)/2
    x=1
    while x<=n:
        sum=sum-x*2
        x=2*x
    print(sum)