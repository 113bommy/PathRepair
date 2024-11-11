# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n,k=map(int,input().split())
a=k
if k>=n-1:
	print(n-1)
else:
	for i in range(n-1-k):
		a+=i+2
		print(a)
	print(a)	