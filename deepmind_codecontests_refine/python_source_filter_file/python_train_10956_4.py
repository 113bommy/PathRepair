
T = int(input())
for t in range(T):
	n, m = map(int, input().split())
	nums = set()
	even = True
	curr_med = (2**m - 1) // 2
	for i in range(n):
		num = int(input(),2)
		nums.add(num)
		if num > curr_med:
			if not even:
				curr_med -= 1
				while curr_med in nums:
					curr_med -= 1				
		elif num < curr_med:
			if even:
				curr_med += 1
				while curr_med in nums:
					curr_med += 1	
		else:
			if even:
				curr_med += 1
				while curr_med in nums:
					curr_med += 1					
			else:
				curr_med -= 1
				while curr_med in nums:
					curr_med -= 1	
		if even:
			even = False
		else:
			even = True
	binary_string = "{0:b}".format(curr_med)
	print((len(binary_string) - m)*'0'+binary_string)
	#print("{0:b}".format(curr_med))



