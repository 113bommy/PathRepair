import sys
reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__

cnt = {}
for _ in range(8) :
	cnt[_] = 0
n = int(input())
for x in list(map(int, input().split())) :
	cnt[x] += 1
ans = []
for x, y, z in [(1, 2, 4), (1, 2, 6), (1, 3, 6)] :
	mnm = min(cnt[x], cnt[y], cnt[z]);
	if mnm > 0 :
		ans.extend([(x, y, z)] * mnm)
		cnt[x] -= mnm
		cnt[y] -= mnm
		cnt[z] -= mnm
if len(ans) * 3 == n :
	for x, y, z in ans :
		print(x, y, z)
else :
	print("-1")