m=int(input())
while m:
    n=int(input())
    sum=(n*(n+1))//2
    i=1
    m-=1
    while i<=n:
        sum-=2*i
        i*=2
    print(sum)