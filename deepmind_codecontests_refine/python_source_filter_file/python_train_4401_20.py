for _ in range(int(input())):
	n=int(input())
	arr=list(map(int,input().split()))
	l=set(arr)
	if len(l)==n:
		print(1)
	else:
		print(n)