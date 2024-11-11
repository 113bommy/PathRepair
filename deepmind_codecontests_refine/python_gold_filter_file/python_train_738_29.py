from sys import stdin

def main():
	n = int(input())
	ans = 0
	if n % 2 == 1:
		ans = 1
		d = 3 
		while d*d <= n and n % d != 0:
			d += 2
		if d*d > n:
			d = n
		n = n - d
		
	ans += n // 2

	print(ans)

	return


if __name__ == '__main__':
	main()