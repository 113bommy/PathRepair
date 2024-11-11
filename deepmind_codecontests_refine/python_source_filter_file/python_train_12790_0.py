from collections import Counter
N,M = map(int,input().split())
src = list(map(int,input().split()))

if M == 1:
    print(N // 2)
    exit()

hist = [0] * M
ctrs = [Counter() for i in range(M)]
for a in src:
    hist[a%M] += 1
    ctrs[a%M].update([a])

ans = 0
for i in range(1, (M+1)//2):
    j = M - i
    if hist[j] < hist[i]: i,j = j,i
    ans += hist[i]
    rem = hist[j] - hist[i]
    n = sum([v//2 for v in ctrs[j].values()])
    ans += min(rem, n)

ans += sum(ctrs[0].values()) // 2
if M%2 == 0:
    ans += sum(ctrs[M//2].values()) // 2

print(ans)