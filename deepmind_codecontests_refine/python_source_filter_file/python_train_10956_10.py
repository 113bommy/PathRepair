from bisect import bisect_left
def less_than(mid):
	ind=bisect_left(arr,mid)
	return mid-ind


for _ in  range(int(input())):
	n,m=map(int,input().split())
	arr=[]
	a=set()
	for i in range(n):
		arr.append(int(input(),2))
		a.add(arr[-1])
	arr.sort()


	
	total=2**m-n
	l=0 
	r=2**m-1

	while l<=r:
		mid=l+(r-l)//2
		l_mid=less_than(mid)
		# print(l,r,mid,l_mid)
		if mid not in a and abs(total-2*l_mid-1)<=1:
			# print(mid,m)
			print(bin(mid)[2:].zfill(m))
			break
		else:
			if l_mid>=total-l_mid:
				r=mid-1
			else:
				l=mid+1
	# assert(False)
