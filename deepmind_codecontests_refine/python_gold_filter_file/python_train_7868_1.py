from collections import defaultdict

class Solution():
	def division(n, a):
		prefix_sum, suffix_sum = [0]*(n), [0]*(n)
		prefix_sum[0], suffix_sum[n-1] = a[0], a[n-1]

		for i in range(1,n):
			prefix_sum[i] = prefix_sum[i-1]+a[i]
			suffix_sum[n-1-i] = suffix_sum[n-i]+a[n-1-i]

		prefix_check, suffix_check = defaultdict(bool), defaultdict(bool)

		for i in range(n):
			prefix_check[a[i]] = True

			diff = prefix_sum[i] - (0 if i == n-1 else suffix_sum[i+1])
			diff = int(diff/2) if diff%2 == 0 else -1*abs(diff)

			if diff in prefix_check:
				return True

			suffix_check[a[n-1-i]] = True

			diff = suffix_sum[n-1-i] - (0 if i == n-1 else prefix_sum[n-2-i])
			diff = int(diff/2) if diff%2 == 0 else -1*abs(diff)


			if diff in suffix_check:
				return True

		return False

n = int(input())

a = list(map(int, input().strip(' ').split(' ')))

print("YES" if Solution.division(n, a) else "NO")
