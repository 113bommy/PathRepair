def check(times, nums, m):
	current = 0 if (nums[0] + times >= m) else nums[0]
	for i in range(1, len(nums)):
		if nums[i] == current:
			continue
		if nums[i] < current and current - nums[i] > times:
			return False
		if nums[i] > current and m - nums[i] + current > times:
			current = nums[i]
	return True

def main():
	n, m = [int(x) for x in input().split()]
	nums = [int(x) for x in input().split()]
	if check(0, nums, m):
		return 0
	l = 0
	r = m
	while l + 1 < r:
		mid = (l + r) // 2
		print(l, r, mid)
		if check(mid, nums, m):
			r = mid
		else:
			l = mid
	return r


if __name__ == '__main__':
	print(main())