mx=[]
mn=[]
n=int(input())
c=0

def  f(ar,target,end):
	start=0
	ans=-1
	while(start<=end):
		mid=(start+end)//2
		if(ar[mid]<=target):
			start=mid+1
		else:
			ans=mid
			end=mid-1
	return ans
def countGreater(arr, n, k): 
    l = 0
    r = n - 1
  
    # Stores the index of the left most element 
    # from the array which is greater than k 
    leftGreater = n 
  
    # Finds number of elements greater than k 
    while (l <= r): 
        m = int(l + (r - l) / 2) 
  
        # If mid element is greater than 
        # k update leftGreater and r 
        if (arr[m] > k): 
            leftGreater = m 
            r = m - 1
  
        # If mid element is less than 
        # or equal to k update l 
        else: 
            l = m + 1
  
    # Return the count of elements  
    # greater than k 
    return (n - leftGreater) 


for i in range(n):
	a=list(map(int,input().split()))
	an=0
	for j in range(2,a[0]+1):
		if(a[j]>a[j-1]):
			an=1
			c+=1
	if(an==0):
		mx.append(max(a[1:]))
		mn.append(min(a[1:]))

ans=c*n
mx.sort()
for i in range(len(mn)):
	ind=countGreater(mx,len(mx),mn[i])
	ans+=c
	ans+=ind
print(ans)