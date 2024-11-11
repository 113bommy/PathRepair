import sys
input = sys.stdin.readline

def solve():
	N = int(input())
	s = input().rstrip()

	for i, c in enumerate(s):
		if i < N-1 and c != s[i+1]:
			print(i, i+1)
			return
	print(-1, -1)

	
if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		solve()
