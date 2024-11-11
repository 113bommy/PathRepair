n, k = map(int, input().split())
if k == 1 or k == n:
    print(6 + 3 * (n - 2))
else:
    if k * 2 > n:
        k = n - k  + 1   
    b = 5 + 3 * (n - 2) + k
    print(b)