import sys

def input():
	return sys.stdin.readline().rstrip()

def input_split():
	return [int(i) for i in input().split()]

t = int(input())
for tests in range(t):
	s = input()
	n = int(input())
	b = input_split()
	q = []
	ans = []
	for i in range(len(b)):
		if b[i] == 0:
			q.append(i)
			ans.append(len(q))
	# print("intial",q)
	while (len(q) < n):
		new_q = []
		for i in range(n):
			if i in q:
				continue
			runnning_sum = 0
			for j in q:
				runnning_sum += abs(i - j)
			if runnning_sum == b[i]:
				new_q.append(i)
		ans.append(len(new_q))
		q.extend(new_q)
	# print("ans",ans)
	# print("q",q)
	nums = {}
	for i in s:
		if i not in nums:
			nums[i] = 1
		else:
			nums[i]+=1
	nums = list(nums.items())
	nums.sort(reverse=True)
	ans_ind = 0
	nums_ind = 0
	ret = []
	while (ans_ind < len(ans) and nums_ind < len(nums)):
		if (nums[nums_ind][1] >= ans[ans_ind]):
			ans_ind += 1
			ret.append(nums[nums_ind][0])
		nums_ind += 1
	# print("ret",ret)
	final_s = ["" for i in range(n)]
	q_ind = 0
	ret_ind = 0
	for i in range(len(ret)):
		for j in range(ans[i]):
			final_s[q[q_ind]] = ret[i]
			q_ind += 1
	print("".join(final_s))



