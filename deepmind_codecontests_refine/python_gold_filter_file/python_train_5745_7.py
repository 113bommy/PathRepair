def mapit():
	temp=list(map(int,input().split()))
 
	return temp


def solution():
	n,m,k=mapit()
	arr=mapit()
	curr=m
	for i in range(n-1):
		curr+=arr[i]-max(0, arr[i+1]-k)
		if curr<0:
			print('NO')
			return
		
	print('YES')


		
	return


	



t=int(input())
 
while t:
	t-=1
	solution()