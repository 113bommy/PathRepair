n, m = map(int, input().split())
for k in range(m // n, -1, -1):
    if m % k == 0:
        print(k)
        exit()