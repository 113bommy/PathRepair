[n, m] = list(map(int, input().split(" ")))

if m == n:
    print(0)
    exit(0)
if m == 0 or m == 1:
    print(1)
    exit(0)

print(min(n-m, n//2, m))
