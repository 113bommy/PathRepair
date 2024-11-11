t=int(input())
for i in range(t):
	n,m=map(int,input().split())
	print((24*60-n*60-m)%(24*60))
