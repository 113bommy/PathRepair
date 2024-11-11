m, n = map(int, input().split())
if m >= n and m % n == 0:
    print(-1)
else:
    print(m*2)