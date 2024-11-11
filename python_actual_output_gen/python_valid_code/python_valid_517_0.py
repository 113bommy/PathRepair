import sys
input = lambda:sys.stdin.readline()

int_arr = lambda: list(map(int,input().split()))
str_arr = lambda: list(map(str,input().split()))
get_str = lambda: map(str,input().split())
get_int = lambda: map(int,input().split())
get_flo = lambda: map(float,input().split())

mod = 1000000007

def solve(s,t):
	n,m = len(s)-1,len(t)-1
	while n > 0 and m > 0:
		if s[n] == t[m]:
			n -= 1
			m -= 1
		else:
			n -= 2
	if not m:
		print("YES")
	else:
		print("NO")

for _ in range(int(input())):
	s = str(input())[:-1]
	t = str(input())[:-1]
	solve(s,t)
