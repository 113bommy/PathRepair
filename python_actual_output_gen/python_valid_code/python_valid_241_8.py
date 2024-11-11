
n, k = list(map(int, input().split()))
data = list(map(int, input().split()))
ans = 0 
for item in data:
	tmp = 0
	for elem in str(item):
		if elem == '2' or elem == '4':
			tmp += 1
	if tmp <= k:
		ans += 1
print(ans)
