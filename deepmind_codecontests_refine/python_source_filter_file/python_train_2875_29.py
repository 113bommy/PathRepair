#http://codeforces.com/problemset/problem/854/B
n, k = map(int,input().split())
if(n<=k or k==0):
	print(0,0)
else:
	print(1,min(k+1,n-k))