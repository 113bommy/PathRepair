import sys
input = sys.stdin.readline


n, m = map(int, input().split())
cnt = [0] * n
ans = 0
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if a > b: a, b = b, a
    cnt[a] += 1
    if cnt[a] == 1: ans += 1
for _ in range(int(input())):
    x = list(map(int, input().split()))
    if x[0] == 1:
        a, b = x[1], x[2]
        a -= 1
        b -= 1
        if a > b: a, b = b, a
        cnt[a] += 1
        if cnt[a] == 1: ans += 1
    elif x[0] == 2:
        a, b = x[1], x[2]
        a -= 1
        b -= 1
        if a > b: a, b = b, a
        cnt[a] -= 1
        if not cnt[a]: ans += 1
    else:
        print(n - ans)