import os, sys, math
import collections

if os.path.exists('testing'):
	name = os.path.basename(__file__)
	if name.endswith('.py'):
		name = name[:-3]
	src = open(name + '.txt', encoding='utf8')
	input = src.readline

def solve():
	def count_rec(fr, to):
		if n < fr:
			return 0
		if fr <= n <= to:
			return n - fr + 1
		return to - fr + 1 + count_rec(fr * 2, to * 2 + 1)
	def count(x):
		if x & 1:
			return count_rec(x, x)
		return count_rec(x, x + 1)
	def binary_search(fr, to, o):
		if fr == to:
			return fr * 2 + o
		s = (fr + to) // 2
		v = count(s * 2 + o)
		if v > k:
			return binary_search(s + 1, to, o)
		return binary_search(fr, s, o)
	v1 = binary_search(0, n // 2, 0)
	v2 = binary_search(0, n // 2, 1)
	return max(v1, v2)

def integers():
	return map(int, input().strip().split()) 

def array_of_integers(q):
	return [
		tuple(map(int, input().strip().split())) for _ in range(q)
	]

n, k = integers()
res = solve()
print(res)
