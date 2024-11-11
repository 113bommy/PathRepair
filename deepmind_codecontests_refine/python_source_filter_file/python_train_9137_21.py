N, P = map(int, input().split())
S = input()
if 10 % P == 0:
    ans = 0
    for r in range(N):
        if int(S[r]) % P == 0:
            ans += r + 1
    print(ans)
    exit()

d = [0] * (N + 1)
ten = 1
for i in range(N - 1, -1, -1):
    a = int(S[i]) * ten % P
    d[i] = (d[i + 1] + a) % P
    ten *= 10
    # ten %= P

cnt = [0] * P
ans = 0
for i in range(N, -1, -1):
    ans += cnt[d[i]]
    cnt[d[i]] += 1
print(ans)