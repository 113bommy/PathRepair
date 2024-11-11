for _ in range(int(input())):
	n =int(input())
	arr=list(map(int, input().split(" ",n-1)))
	arr=set(arr)
	if len(arr)>1:
		print(1)
	else:
		print(len(arr)+1)	
	