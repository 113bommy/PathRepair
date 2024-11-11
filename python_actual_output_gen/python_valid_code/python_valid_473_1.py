def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    i = 0
    while i < n // 2:
        print(a[i + 1], a[i])
        i += 2


for _ in range(int(input())):
    solve()
