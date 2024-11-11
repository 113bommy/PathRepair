from math import ceil

for _ in range(int(input())):
    n, r = map(int, input().split())
    ans = 0
    if n <= 1:
        ans = 1
    elif r >= n:
        ans = (((n) * (n - 1))// 2) + 1
    else:
        ans = ((r) * (r + 1))//2

    print(ans)