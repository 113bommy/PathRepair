from collections import defaultdict

int(input())
mp, sum, res = defaultdict(int), 0, 0
for i, x in enumerate(map(int, input().split()), start =1):
	mp[x] += 1
	sum += x
	res = x*i - sum - mp[x-1] + mp[x+1]
print(res)
