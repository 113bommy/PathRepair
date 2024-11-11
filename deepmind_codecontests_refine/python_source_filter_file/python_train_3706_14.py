nums = [ True for i in range(51) ]
primes = []
for i in range(2, 51):
	if not nums[i]:
		continue
	
	for j in range(i, 51, i):
		nums[j] = False
	nums[i] = True
	
	primes.append(i)

x, y = tuple(map(int, input().strip().split()))
ans = "NO"
if nums[y]:
	for i in range(x+1, 51):
		if nums[i] and i == y:
			ans = "YES"
			break
print(ans)