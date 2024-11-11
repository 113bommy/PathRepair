import sys
input = sys.stdin.buffer.readline


def main():
	t = int(input())
	ans = [0] * t
	for j in range(t):
		n = int(input())
		l = [list(map(int, input().split())) for _ in range(n)]
		s = 0
		m = 1e9
		fb = l[-1][-1]
		for a, b in l:
			t = max(0, a - fb)
			s += t
			if a - t < m:
				m = a - t
			fb = b
		ans[j] = s + m
	print("\n".join(map(str, ans)))


if __name__ == "__main__":
	main()
