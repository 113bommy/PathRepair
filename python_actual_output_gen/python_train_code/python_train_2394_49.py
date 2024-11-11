input()
q = list(map(int, input().split()))
q.sort()

ans = 0
add = 0
for a in q:
    if add < a:
        ans += 1
        add += a
print(ans)