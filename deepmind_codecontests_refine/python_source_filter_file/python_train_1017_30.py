n, k, s = map(int, input().split())

for i in range(1, n+1):
    if i <= k:
        print(s)
    else:
        print(1)