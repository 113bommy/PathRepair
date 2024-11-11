# n, a, b = list(map(lambda k: int(k), input().split(' ')))
# s = input()

def solveQ1(n, a, b, s):
	if s[a-1] == s[b-1]:
		return 0
	c = s[b-1]
	n = len(s)
	min_dist = n
	for i in range(n):
		if s[i] == c:
			min_dist = min(abs(a-1-i), min_dist)
	return min_dist

# n, k = list(map(lambda i: int(i), input().split(' ')))

def solveQ2(n, k):

	if n == 1:
		return 1
	if k == pow(2, n-1):
		return n
	if k > pow(2, n-1):
		return solveQ2(n - 1, k - pow(2, n-1))
	else:
		return solveQ2(n - 1, k)
# print(solveQ2(n, k))

# lst = [1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,6,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1]
n = int(input())
def solveQ3(n):
	if n == 1:
		print(-1)
		return
	else:
		print("{0} {1} {2}".format(n, n+1, n*(n+1)))
		return

solveQ3(n)
