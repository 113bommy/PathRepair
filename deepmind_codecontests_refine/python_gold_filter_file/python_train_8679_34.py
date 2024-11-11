n=int(input())
arr=[False]*(3002)

a=list(map(int,input().split()))

for i in a:
	arr[i]=True

for i in range(1,3002):
	if(not arr[i]):
		print(i)
		break

		