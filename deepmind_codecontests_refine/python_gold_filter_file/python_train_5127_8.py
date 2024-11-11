for _ in range(int(input())):
    n, k = map(int, input().split())
    d = None
    if k==0:print(n);continue
    for i in range(2, int(pow(n, 0.5)+1)):
        if n%i==0:
            d=i
            break
    if d:
        ans = d+n;k-=1;ans+=2*k
    else:
        ans = 2*n
        k-=1;ans+=k*2
    print(ans)