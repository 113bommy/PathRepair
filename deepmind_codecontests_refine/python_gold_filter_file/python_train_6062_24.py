
def maxSelfGrade(n,m,arr):
	if sum(arr)>=m:
		return m
	else:
		return sum(arr)

t=int(input())
for i in range(t):
	n,m=map(int,input().split())
	arr=list(map(int,input().split()))
	print(maxSelfGrade(n,m,arr))