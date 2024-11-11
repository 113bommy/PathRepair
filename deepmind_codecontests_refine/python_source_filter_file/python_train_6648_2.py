afrom collections import Counter
n, k = map(int, input().split())
ps = [input() for _ in range(n)]
heads = Counter((p[0] for p in ps))
ans = 0
while len(heads) >= k:
    ans += 1
    for h, c in heads.most_common()[:k]:
        if c==1:
            heads.pop(h)
        else:
            heads[h] -= 1
print(ans)