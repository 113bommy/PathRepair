from collections import Counter
n = int(input())
cnt = Counter([int(x) for x in input().split()])
ans = cnt[0] * (cnt[0] - 1) // 2
for i in range(1, 10):
	ans += cnt[i] * cnt[-i]
print(ans)
