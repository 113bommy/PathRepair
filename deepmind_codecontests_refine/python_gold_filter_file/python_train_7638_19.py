import io,sys,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def printArr(arr):
	sys.stdout.write(" ".join(map(str,arr)) + "\n")

def solve(arr,n,mod):
	arr.sort()
	leftMedian = n//2 -1
	rightMedian = n//2
	remainder = arr[0]%mod
	answer=0
	answer2=0
	for i in range(n):
		if arr[i]%mod !=remainder:
			return -1
		answer+=abs(arr[leftMedian]-arr[i])//mod
		answer2+=abs(arr[rightMedian]-arr[i])//mod
	return min(answer,answer2)

t=1
while t>0:
	s=input().decode().strip().split()
	n,m,d=int(s[0]),int(s[1]),int(s[2])
	arr=list()
	for i in range(n):
		temp=[int(i) for i in input().decode().strip().split()]
		arr.extend(temp)
	answer=solve(arr,n*m,d)
	sys.stdout.write(str(answer)+'\n')
	t-=1
