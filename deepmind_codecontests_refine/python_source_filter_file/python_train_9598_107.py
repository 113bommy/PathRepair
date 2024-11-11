def solve():
	n, a, b = map(int, input().split())

	res = 0
	for i in range(a + 1, n + 1):
		if(n - i <= b):
			res = res + 1
		else:
		    break;
	print(res)
	
solve()