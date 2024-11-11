from collections import Counter
N, P = map(int, input().split())
S = list(map(int, list(input())))
ans = 0
if P in (2, 5):
    cnt = 0
    for i, s in enumerate(S):
        if s % P == 0:
            ans += i+1
else:
    S.reverse()
    now = 0
    d = [0] * (N+1)
    for i in range(N):
        now += S[i] * pow(10, i, P)
        now %= P
        d[i] = now % P
    c = Counter(d)
    for i, v in c.items():
        ans += v*(v-1)//2
    #print(d)

print(ans)
 