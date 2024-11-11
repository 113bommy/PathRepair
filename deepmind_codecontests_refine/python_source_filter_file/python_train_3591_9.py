def main():
	n, x = map(int, input().split())
	if n == 1:
		print(1)
		return
	print(x + 1 if x - 1 <= n - x else x - 1)

if __name__ == '__main__':
	main()
