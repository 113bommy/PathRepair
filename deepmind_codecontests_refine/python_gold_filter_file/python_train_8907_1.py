''' Author @isumit '''
import math
def solve():
	A, B= map(int, input().split())
	gcdab = math.gcd(A, B)
	divisors = []
	i = 1
	while i*i <= gcdab:
		if gcdab % i == 0 :
			divisors.append(i)
			divisors.append(gcdab//i)
		i += 1
	divisors = sorted(divisors)
	for _ in range(int(input())):
		left, right = map(int, input().split())
		res = -1
		for i in divisors:
			if left <= i and i <= right:
				res = max(res, i)
		print(res)
Testcase = 1
#Testcase = int(input())
for _ in range(Testcase):
	solve()
''' https://codeforces.com/problemset/problem/75/C '''