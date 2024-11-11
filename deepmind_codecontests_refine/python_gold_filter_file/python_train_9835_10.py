
def main():
	n, x = map(int, input().split())
	t = 1
	ans = 0
	for i in range(n):
		l, r = map(int, input().split())
		while t + x <= l:
			t += x
		ans += r - t + 1
		t = r + 1
	print(ans)

if __name__ == '__main__':
	main()
