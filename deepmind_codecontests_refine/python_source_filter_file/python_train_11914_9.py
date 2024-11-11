n,a,b = map(int,input().split())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))

for i in range(n):
	if i not in l1:
		print(2,end=" ")
	else:
		print(1,end=" ")