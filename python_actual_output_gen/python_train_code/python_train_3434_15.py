def getinput():
    return [int(x) for x in input().strip().split()]

n, k = getinput()

arr=getinput()

for i in range(1, n): arr[i]+=arr[i-1]

maxval=max(arr)
minval=min(arr)

l=min(0, minval)
l=abs(l)
r=k-maxval

if l>r: print(0)
else: print(r-l+1)