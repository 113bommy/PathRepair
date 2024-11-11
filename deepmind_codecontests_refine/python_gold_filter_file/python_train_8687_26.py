n, m, k = list(map(int, input().split()))

nums = []
for _ in range(m+1):
	nums.append(int(input()))

# we need maximum 10 place to store numbers upto 1000
fedor = list(map(int,'{0:020b}'.format(nums[-1])))
# print(fedor)
ans = 0
for i in range(m):
	bits = list(map(int,'{0:020b}'.format(nums[i])))
	k_i = 0
	for j in range(20):
		if bits[j] != fedor[j]:
			k_i += 1
	if k_i <= k:
		ans += 1
print(ans)
	