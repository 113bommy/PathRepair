def main():
	n = int(input())
	s = []
	for i in range(n):
		s.append(input())
	for i in range(n):
		for j in range(n):
			cnt = 0
			for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
				ii = i + di
				jj = j + dj
				if ii >= 0 and ii < n and jj >= 0 and jj < n and s[ii][jj] == 'o':
					cnt += 1
			if cnt % 2:
				print("NO")
				return
	print("YES")

if __name__ == '__main__':
    main()
