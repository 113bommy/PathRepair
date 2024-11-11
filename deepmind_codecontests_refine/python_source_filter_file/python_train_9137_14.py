N, P = map(int, input().split())
S = input()
ans = 0
rui = [0] * (N + 1)
if 10 % P == 0:
    for i in range(len(S)):
        if int(S[i]) % P == 0:
            ans += i + 1
    print(ans)
    exit()

t = 1
for i in reversed(range(N)):
    tmp = int(S[i]) * t % P
    rui[i] = (rui[i + 1] + tmp) % P
    t *= 10
    t %= P

cnt = [0] * (N + 1)
for i in reversed(range(N + 1)):
    ans += cnt[rui[i]]
    cnt[rui[i]] += 1
print(ans)