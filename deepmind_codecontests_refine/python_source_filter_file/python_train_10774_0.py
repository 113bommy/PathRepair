def max_sum(nums, shift):
	res = 0
	res_m = 0
	cur_sum = 0
	cur_m_sum = 0
	for i in range(len(nums)):
		cur_sum += (nums[i] + shift)
		cur_m_sum += (nums[i] + shift)
		res = max(res, cur_sum)
		cur_sum = max(0, cur_sum)
		res_m = min(res_m, cur_m_sum)
		cur_m_sum = min(0, cur_m_sum)
	return res, -res_m

def weaks(nums, shift):
	return max_sum(nums, shift)

def main():
	int(input())
	nums = list(map(int, input().split()))
	l = -10000
	r = 10000
	ans = max(weaks(nums, 0))
	w1 = 1
	w2 = -1
	PREC = 10**-6
	while abs(w1 - w2) >= PREC and abs(w1 - w2) > PREC * max(w1, w2):
		m = (r + l)/2
		print (w1,w2,r,l,m)
		w1, w2 = weaks(nums, m)
		# print(w1, w2)
		if w1 > w2:
			r = m
		else: 
			l = m
	print ((w1 + w2) / 2)

# print (weaks([1,2,3],-2500.0))
main()
