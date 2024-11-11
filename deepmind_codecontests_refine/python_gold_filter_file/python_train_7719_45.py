n, m = list(map(int, input().split()))
if m == 0:
    print(1)
    exit()
print(min(m, n - m))