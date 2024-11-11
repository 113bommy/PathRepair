T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    sorted(a, reverse=True)
    print(min(a[1] - 1, n - 2))
