from collections import Counter

N = int(input())
*A, = map(int, input().split())
cnt = Counter(A)
A = sorted(A, reverse=True)
ans = 0
for a in A:
    if a & (a - 1) != 0:
        cand = (1 << ((a - 1).bit_length()))
        if cnt[a] == 0 or cnt[cand] == 0: continue
    else:
        cand = a
        if cnt[a] < 2: continue
    ans += 1
    cnt[a] -= 1; cnt[cand] -= 1
print(ans)