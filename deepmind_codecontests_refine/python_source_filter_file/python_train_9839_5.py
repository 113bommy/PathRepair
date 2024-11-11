t=int(input())
while t:
    n=int(input())
    sum=(n*(n+1))//2
    i=2
    t-=1
    while i<=n:
        sum-=2*i
        i*=2
    print(sum)    