cnt = 0
INFTY=10**10
def merge_sort(a,left,right):
	if left+1<right:
		mid=(left+right)//2
		merge_sort(a,left,mid)
		merge_sort(a,mid,right)
		merge(a,left,mid,right)

def merge(a,left,mid,right):
	L=a[left:mid]
	R=a[mid:right]
	L.append(INFTY)
	R.append(INFTY)
	global cnt
	i=0
	j=0
	for k in range(left,right):
		cnt+=1
		if L[i] <= R[j]:
			a[k]=L[i]
			i+=1
		else:
			a[k]=R[j]
			j+=1
			
	
n=int(input())
cnt=0
a=list(map(int,input().split()))
merge_sort(a,0,len(a))
print(*a)
print(cnt)
