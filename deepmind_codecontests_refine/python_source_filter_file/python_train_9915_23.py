import bisect
def solve():
	n,k=map(int,input().split())
	lis=list(map(int,input().split()))
	mount=[]
	for i,v in enumerate(lis[1:len(lis)-1],1):
		if v>lis[i-1] and v>lis[i+1]:
			mount.append(i+1)

	max_mount=0
	index=0

	for i in range(1,len(lis)+1):
		mt=bisect.bisect_left(mount,i+k-1)
		ind=bisect.bisect_left(mount,i)
		if mt-ind>max_mount:
			max_mount=mt-ind
			index=i
	print(max_mount+1,index)

t=int(input())
for i in range(t):
	solve()

