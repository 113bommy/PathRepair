def main():
	a,b = list(map(int, input().split()))
	solve_data(a,b)

def solve_data(n,m):
	a = "54"*(2230//2)+"6"
	b = "45"*(2230//2)+"4"
	print(a,b)

if __name__ == '__main__':
	main()