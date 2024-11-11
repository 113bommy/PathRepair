r=int(input());
for t in range(0,r):
    n, k= map(int, input().split());x=9999999999;
    i=1
    while i*i<=n:
        if n%i==0:
            if i<=k:x=min(x,n//i)
            if n//i<=k:x=min(x,i)
        i+=1
    print(x)
