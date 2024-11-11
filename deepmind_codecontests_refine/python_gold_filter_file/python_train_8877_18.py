def solve():
	a,b,c,d = map(int, input().split())
	print(max(a+b,c+d))
if __name__ == '__main__':
	for _ in range (int(input())):
		solve()