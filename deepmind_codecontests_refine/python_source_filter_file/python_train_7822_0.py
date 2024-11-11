import math
from collections import defaultdict, Counter, deque




def primeFactor(n):
	if n % 2 == 0:
		return 2
	i = 3
	while (i ** 2) <= n:
		if n % i == 0:
			return i 
		i += 1
	return n



def main():
	n = int(input())
	arr = list(map(int, input().split()))

	stack = []
	nums = [0]
	l = 0
	r = n - 1

	while l <= r:
		if arr[l] == arr[r] and l != r and arr[l] < nums[-1]:
			u1 = [0]
			left = l
			right = r
			while left < right and u1[-1] < arr[left]:
				u1.append(arr[left])
				left += 1
			u2 = [0]
			left = l
			right = r
			while right > left and u2[-1] < arr[right]:
				u2.append(arr[right])
				right -= 1

			if len(u1) > len(u2):
				stack += ['L']  * (len(u1) - 1)
			else:
				stack += ['R']  * (len(u2) - 1)
			break

		elif nums[-1] < arr[l] and nums[-1] < arr[r] and l != r:
			if arr[l] < arr[r]:
				nums.append(arr[l])
				stack.append('L')
				l += 1
			else:
				nums.append(arr[r])
				stack.append('R')
				r -= 1

		elif nums[-1] < arr[l]:
			nums.append(arr[l])
			stack.append('L')
			l += 1
		elif nums[-1] < arr[r]:
			nums.append(arr[r])
			stack.append('R')
			r -= 1
		else:
			break

	print(len(stack))
	# print(stack)
	print(''.join(stack))

if __name__ == "__main__":
	# t = int(input())
	t = 1
	for _ in range(t):
		main()







