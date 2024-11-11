import sys

input = sys.stdin.readline

def main():

	def discrete_binary_search(func, lo, hi):
	    """ Locate the first value x s.t. func(x) = True within [lo, hi] """

	    while lo < hi:
	        mi = lo + (hi - lo) // 2
	        if func(mi):
	            hi = mi
	        else:
	            lo = mi + 1

	    return lo

	def check(x):
		p = x//n
		q = x%n

		xmove = p*prex[n] + prex[q]
		ymove = p*prey[n] + prey[q]

		return (abs(nx - xmove) + abs(ny - ymove) <= x)

	a, b = map(int, input().split())
	x, y = map(int, input().split())
	n = int(input())
	s = input()

	INF = 10**17

	nx = x-a
	ny = y-b

	nz = nx + ny

	dx = [0]*n
	dy = [0]*n

	for i in range(n):
		c = s[i]
		if c == "U":
			dy[i] = 1
		elif c == "D":
			dy[i] = -1
		elif c == "L":
			dx[i] = -1
		else:
			dx[i] = 1

	prex = [0]
	prey = [0]

	for i in range(n):
		prex.append(prex[-1] + dx[i])
		prey.append(prey[-1] + dy[i])

	if check(INF):
		print(discrete_binary_search(check, 0, INF))
	else:
		print(-1)

main()