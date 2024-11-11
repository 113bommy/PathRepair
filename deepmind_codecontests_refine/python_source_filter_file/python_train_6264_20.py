n=int(input())
arr=list(map(int,input().split()))
m=arr.index(max(arr))
i=m
ans="YES"
while i:
    if arr[i-1]>arr[i]:
        ans="NO"
    i-=1
i=m
while i<len(arr)-1:
    if arr[i+1]<arr[i]:
        ans="NO"
    i+=1
print(ans)
