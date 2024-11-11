def solve(t):
    cnt = 0
    for i in a:
        if abs(i - t) >= 1:
            if i > t:
                cnt += i - t - 1
            else:
                cnt += t - i - 1
    return cnt


n = int(input())
a = list(map(int, input().split()))

t_now = -1
ans = 10000000

for t in range(1, 101):
    now = solve(t)
    if now < ans:
        t_now = t
        ans = now

print(t_now, ans)
