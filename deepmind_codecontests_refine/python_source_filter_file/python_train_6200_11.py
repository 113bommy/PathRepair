freq = {}
n = int(input())
a = [int(x) for x in input().split()]
ans = 0
for x in a:
	for b in range(30):
		ans += freq.get(2**b-x,0)
	freq[x] = freq.get(x,0)+1
print(ans)