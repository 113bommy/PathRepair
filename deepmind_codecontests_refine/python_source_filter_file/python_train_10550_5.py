n = int(input())
m = 1
arr = []
while(True):
	mm = (m*(m+1))//2
	if mm>n:
		break
	arr.append(mm)
	m+=1

ll = len(arr)
flag = 0
for i in range(ll):
	curr = arr[i]
	req = n-curr
	l = i+1
	r = ll-1
	while(l<=r):
		mid = (l+r)//2
		if arr[mid]>=req:
			r = mid-1
		else:
			l = mid+1
	if i<l<ll and arr[l]==req:
		flag=1
		break
if flag==1:
	print("YES")
else:
	print("NO")
