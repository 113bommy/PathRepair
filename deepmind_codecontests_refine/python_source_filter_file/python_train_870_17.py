# https://codeforces.com/contest/294/problem/A
def birds(n,arr):
	q=int(input())
	for i in range(q):
		x,y=map(int,input().split())
		# if n==1:
		# 	arr[0]=0
		# elif x==n:
		# 	arr[x-2]+=(y-1)


		# elif x==1:
		# 	arr[x]+=(arr[0]-y)
		


		# else:
		arr[x-2]+=(y-1)
		arr[x]+=(arr[x-1]-y)

		arr[x-1]=0


	for i in range(n):
		print(arr[i])

	return


n=int(input())
arr=[int(arr) for arr in input().split()]
arrnew=[0]
for i in range(n):
	arrnew.append(arr[i])

arrnew.append(0)

birds(n,arrnew)

