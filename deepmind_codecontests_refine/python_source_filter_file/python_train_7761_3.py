import sys
from math import sqrt, gcd, ceil, log
# from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
# from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))

# sys.setrecursionlimit(5*10**6)


def main():
	n, m, k = read(); mat = []
	for i in range(n):mat.append(list(input().strip()))
	cells = defaultdict(list)
	cell = 0
	visited = defaultdict(int)
	def dfs(x, y, cell):
		visited[(x, y)] = 1
		cells[cell].append((x,y))
		for child in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
			i, j = child
			if 0 < i < n-1 and 0 < j < m-1 and not visited[(i, j)] and mat[i][j] == ".":
				dfs(i, j, cell)

	for i in range(n):
		step = 1
		if not i in [0, n-1]:
			step = m-1
		for j in range(0, m, step):
			if mat[i][j] == "."and not visited[(i, j)]:
				# cell += 1
				dfs(i, j, cell)

	cells = defaultdict(list)

	for i in range(1, n-1):
		for j in range(1,m-1):
			if mat[i][j] == "."and not visited[(i, j)]:
				cell += 1
				dfs(i, j, cell)
	print(cells)
	arr = [(len(cells[i]), i) for i in cells]
	arr.sort()
	count = 0
	# print(arr)
	for i in range(len(arr)-k):
		cell = arr[i][1]
		for j in cells[cell]:
			mat[j[0]][j[1]] = "*"
			count += 1
	# print(count)
	for i in mat:print(("").join(i))

			






if __name__ == "__main__":
	main()