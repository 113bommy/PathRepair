from collections import Counter
n, k = map(int, input().split())
m = sorted(list(map(int, input().split())), reverse=True)
c = [n] + list(map(int, input().split()))
cnt = Counter(m)
tmp = 0
size = 1
for i in range(k, 0, -1):
	tmp += cnt[i]
	size = max(size, (tmp-1)//c[i]+1)

ans = [[] for _ in range(size)]
for i, x in enumerate(m):
	ans[i%size].append(x)

print(size)
for a in ans:
	print(len(a), *a)