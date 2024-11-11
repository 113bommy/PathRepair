def main():
	n, k = [int(_) for _ in input().split()]

	a = [int(_) for _ in input().split()] + [1, 10**9]

	a.sort()

	if a[k] < a[k + 1]:
		print(a[k])
	else:
		print(-1)

if __name__ == '__main__':
	main()
