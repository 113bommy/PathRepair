'''input
8
5 6 2
2 4 3 5 7
5 11 2
2 4 3 5 7
3 2 3
4 2 6
5 2 3
10 1 3 9 2
2 10000 2
10000 10000
2 9999 2
10000 10000
4 6 4
3 2 3 2
5 5 3
1 2 2 1 2
'''
def check(x,arr,p,n,k):
	ans=sum(arr[0:x])
	index=x+k-1
	if ans<=p:
		p-=ans
		ans=x
	else:
		ans=0
	while(index<n):
		if arr[index]<=p:
			p-=arr[index]
			ans+=k
			index+=k
		else:
			break
	return ans
def bin_search(l,r,arr,p,n,k):
	if r-l+1<10:
		ans=0
		for i in range(l,r+1):
			a=check(i,arr,p,n,k)
			#print(i,a)
			ans=max(ans,a)
		return ans
	mid=(l+r)//2
	see=check(mid,arr,p,n,k)
	see2=check(mid+1,arr,p,n,k)
	if see2>see:
		return bin_search(mid+1,r,arr,p,n,k)
	else:
		return bin_search(l,mid,arr,p,n,k)
t=int(input())
for _ in range(t):
	n,p,k=[int(x) for x in input().split()]
	arr=list(map(int,input().split()))
	arr.sort()
	print(bin_search(0,n-1,arr,p,n,k))