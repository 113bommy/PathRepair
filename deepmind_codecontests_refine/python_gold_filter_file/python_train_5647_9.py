def main():
	for _ in range(int(input())):
		n, m = map(int, input().split())
		result = [('B' * m)[:m], f"W{('B' * m)[1:m]}"]
		for _ in range(n - 1):
			print(result[0])
		else:
			print(result[1])

if __name__ == '__main__':
	main()
