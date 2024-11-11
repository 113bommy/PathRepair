def main():
	(n, k, m) = (int(x) for x in input().split())
	A = [int(x) for x in input().split()]
	solver(n, k, m, A)


def solver(n, k, m, A):
	rems = [0] * m
	nums = [[] for i in range(m)]	
	for x in A:
		rem = x % m
		rems[rem] += 1
		nums[rem].append(x)
	for i in range(m):
		if rems[i] >= k:
			print("Yes")
			for x in nums[i]:
				print(x, end = " ")
			return
	print("No")

# n = 3
# k = 2
# m = 3
# A = [1, 8, 4]
# solver(n, k, m, A)

main()