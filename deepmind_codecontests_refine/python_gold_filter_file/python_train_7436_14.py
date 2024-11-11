n, k = map(int, input().split())
s = input().strip()
if k - 1 > n - k:
    for i in range(k, n):
        print("RIGHT")
    print("PRINT", s[n - 1])
    for i in range(n - 1, 0, -1):
        print("LEFT")
        print("PRINT", s[i - 1])
else:
    for i in range(k - 1):
        print("LEFT")
    print("PRINT", s[0])
    for i in range(1, n):
        print("RIGHT")
        print("PRINT", s[i])
