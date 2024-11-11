import sys
import math

# sys.stdin = open('../cpp/in.txt','r')
# sys.stdout = open('../cpp/out.txt','w')

t = int(sys.stdin.readline())
def differ(u,cnt):
	ret = mx = 0
	for i in range(26):
		ret += cnt[u][i]
		mx = max(mx,cnt[u][i])
	return ret-mx

for _ in range(t):
	n, k = map(int, sys.stdin.readline().split())
	s = sys.stdin.readline()
	cnt = [[0 for i in range(26)] for j in range((k + 1) // 2)]

	for i in range(n):
		cnt[min(i % k, k - 1 - i%k)][ord(s[i]) - ord('a')] += 1

	ans = 0

	for i in range(math.ceil(k/2)):
		ans += differ(i,cnt)

	print(ans//2)