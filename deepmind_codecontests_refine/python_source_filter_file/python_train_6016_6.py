from itertools import combinations_with_replacement as c
n, m, q = [int(i) for i in input().split()]
abc = [[int(i) for i in input().split()] for _ in range(q)]
aa = list(range(1,m+1))
ans = 0
for bb in c(aa,m):
    cc = 0
    for a, b, c, d in abc:
        if bb[b-1] - bb[a-1] == c:
            cc += d
    ans = max(ans, cc)
print(ans)