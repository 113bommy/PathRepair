def main():
	n, m, c = input().split()
	n = int(n)
	m = int(m)

	a = []
	for i in range(n):
		a.append(input())

	cnt = set()
	for i in range(n):
		for j in range(m):
			if a[i][j] == '.' or a[i][j] == c:
				continue

			if a[min(i+1, n - 1)][j] == c or a[max(i-1, 0)][j] == c or a[i][max(j-1, 0)] == c or \
				a[i][min(j+1, m - 1)] == c:
				cnt.add(a[i][j])


	print(len(cnt))

if __name__ == '__main__':
	main()


