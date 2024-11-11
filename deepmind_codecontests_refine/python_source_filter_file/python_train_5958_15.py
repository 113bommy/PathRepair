from math import *
if __name__ == '__main__':
	for _ in range (int(input())):
		n,g,b = map(int, input().split())
		a = ceil(n//2)
		high = ceil(a/g)
		ans = (high-1)*b+a
		print(max(n,ans))