import sys
from collections import defaultdict, deque

inp = sys.stdin.readline
read = lambda: list(map(int, inp().split()))


def e():
	res = 0
	n, m = read()
	mat = [None]*n
	for i in range(n):
		mat[i] = read()

	for col in range(m):
		b = [0]*n#defaultdict(int)
		for row in range(n):
			elem = mat[row][col]
			place = row*m + col + 1
			# print(place, elem, n, ((place - elem)//n if place >= elem else (n - place + elem)//n))
			if elem <= n*m and (place - elem)%m == 0:
				shift = ((place - elem)//m if place >= elem else (n + place - elem)//m)
				# print(shift)
				b[shift] += 1
		# print(b)
		res += min(i+n-b[i] for i in range(n))
	print(res)



def d():
	ans = ""
	mex = 0
	q, x = read()
	arr = [0]*q+[0]
	dic = {i: deque([i]) for i in range(x)}

	for i in dic:
		while dic[i][-1] + x < q+1:
			dic[i].append(dic[i][-1] + x)

	for _ in range(q):
		n = int(inp())
		ind = dic[n%x].popleft() if dic[n%x] else n%x
		arr[ind] = 1
		while arr[mex] == 1:
			mex += 1

		ans += str(mex) + "\n"
	print(ans)

if __name__ == "__main__":
	# d()
	e()