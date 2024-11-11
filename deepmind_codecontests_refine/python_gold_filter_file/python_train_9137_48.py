N, P = map(int, input().split())
S = input()

res = 0
if P == 2 or P == 5:
    for i in range(N):
        if int(S[i]) % P == 0:
            res += i + 1
else:
    mp = [0]*P
    mp[0] = 1
    cur = 0
    p10 = 1
    for c in S[::-1]:
        cur = (cur + int(c)*p10) % P
        res += mp[cur]
        mp[cur] += 1
        p10 *= 10
        p10 %= P

print(res)