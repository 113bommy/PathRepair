import sys
input = sys.stdin.readline

def solve(a, b, c, d):
	if a <= b:
		return b

	if d >= c:
		return -1

	x = (a-b) // (c-d)
	if (a-b) % (c-d) > 0:
		x += 1

	return b + x*c


if __name__ == "__main__":
	t = int(input())
	for _ in range(t):
		[a, b, c, d] = map(int, input().split())
		print(solve(a, b, c, d))
