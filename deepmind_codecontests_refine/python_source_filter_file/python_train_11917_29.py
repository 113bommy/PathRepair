def bisectionsearch(L,left,right,k):
	mid=(left+right)//2
	if(right-left==1):
		return left
	else:
		if(L[left]<=k<L[mid]):
			return bisectionsearch(L,left,mid,k)
		elif(L[mid]<=k<L[right]):
			return bisectionsearch(L,mid,right,k)
		elif(k==L[right]):
			return right
		else:
			return -1

n=int(input())
x=int((6*n)**(1/3))
L=[(i+1)*(i+2)*(i+3)//6 for i in range(x)]
print(bisectionsearch(L,0,x-1,n)+1)
