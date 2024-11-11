def s():
	input()
	res = 0
	ss = dict()
	nums = [1]
	while nums[-1] < 10**9: nums.append(nums[-1]*2)
	for i in map(int,input().split()):
		for j in nums:
			if j-i in ss:
				res += ss[j-i]
		if i in ss:ss[i] += 1
		else:ss[i] = 1
	return res
print(s())