for z in range(int(input())):
    k, n, a, b = map(int, input().split())
    if k-n*b <= 0:
        print(-1)
        continue
    low, high = 0, n
    while low != high:
        mid = (low+high+1) >> 1
        if k-(mid-1)*a >a and k-mid*a-(n-mid)*b >= 0:
            low = mid
        else:
            high = mid-1
    print(low)
