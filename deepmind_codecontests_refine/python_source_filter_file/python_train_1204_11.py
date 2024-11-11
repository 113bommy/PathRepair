n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 100100
for i in a:
    cnt[i] += 1
ans = 0
for i in range(2, 100001):
    p = 0
    for j in range(i, 100001, i):
        p += cnt[j]
    ans = max(ans, p)
print(ans)