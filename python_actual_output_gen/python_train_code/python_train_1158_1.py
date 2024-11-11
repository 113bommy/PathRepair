for t in range(int(input())):
    n, k = map(int, input().split())
    m = k % (n-1)
    if m == 0:
        m = -1
    print(n*k//(n-1) + m)