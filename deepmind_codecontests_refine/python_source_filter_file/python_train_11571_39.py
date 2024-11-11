def sol():
    n,w = list(map(int,input().split()))
    if (n <= w):
        print(n)
        return 0
    d = w
    t = w
    for i in range(1,n-w):
        t+=i+1
    print(t)
sol()