for i in range(int(input())):
    n , k = input().split()
    n, k = int(n),int(k)
    l = set(map(int,input().split()))
    if len(l) > k :
        print(-1)
    else:
        print(n*k)
        print((list(l) + [1] * (k - len(l)))*n)