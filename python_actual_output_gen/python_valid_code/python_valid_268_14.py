N = int(input())
S1 = input()
S2 = input()
res = 6
idx = 0
s = []
mod = 1000000007
while idx < N:
    if S1[idx] == S2[idx]:
        s.append(0)
    else:
        s.append(1)
        idx += 1
    idx += 1

res = 3 if s[0] == 0 else 6

for idx in range(1, len(s)):
    prev, cur = s[idx-1], s[idx]
    if prev == 0:
        if cur == 0:
            res *= 2
        else:
            res *= 1
    else:
        if cur == 0:
            res *= 2
        else:
            res *= 3

res %= mod

print(res)
