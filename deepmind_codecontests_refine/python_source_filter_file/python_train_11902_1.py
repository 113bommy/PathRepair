import sys 
input = lambda: sys.stdin.readline().rstrip("\r\n")
for _ in range(int(input())):
	n,x,t = map(int,input().split())
	ans = (t//x)*(n-t//x)
	n_ = t//x
	if n_>=n: 
		ans = n-1 
		n_ -=1
	ans += ((n_)*(n_-1))//2
	print(ans)