def main():
	n, *p = map(int, open(0).read().split())
	c = 40000
	a = [c * i for i in range(n)]
	b = [c * (n - i) for i in range(n)]
	for i, x in enumerate(p):
		a[x - 1] += i
	print(*a)
	print(*b)


if __name__=="__main__":
	main()
