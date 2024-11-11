import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))
aa = list(set(a))
aa.sort()
compress = {aa[i]: i for i in range(len(aa))}
cnt = [0] * len(aa)
idx = [-1] * len(aa)
for i in range(N)[::-1]:
    c = compress[a[i]]
    cnt[c] += 1
    idx[c] = i
ans = [0] * N
for n in range(1, len(aa))[::-1]:
    i = idx[n]
    ans[i] = cnt[n] * (aa[n] - aa[n-1])
    cnt[n-1] += cnt[n]
    idx[n-1] = min(idx[n-1], i)
ans[0] += N * aa[0]
print(*ans, sep='\n')