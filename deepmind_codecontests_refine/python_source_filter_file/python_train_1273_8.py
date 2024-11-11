def binarysearch(arr,val):
    l,r = 0,len(arr)-1
    pos = abs(val)
    while l<r:
        mid = (l+r)//2
        if(arr[mid]>=pos):
            r = mid
        else:
            l = mid
        if (r-l)==1:
            break
    n = len(arr)
    if arr[l]>pos:
        return len(arr)-l
    elif arr[r]>pos:
        return len(arr)-r
    else:
        return 0

n = int(input())
arr = list(map(int,input().split()))
brr = list(map(int,input().split()))
diff = []
for i in range(n):
    diff.append(arr[i]-brr[i])
diff.sort()
# print(diff)
ans = 0
cnt = 0
for i in diff:
    if i>0:
        cnt+=1
for i in range(n):
    if diff[i]<0:
        val = binarysearch(diff,diff[i])
        ans+=val
    elif(diff[i]==0):
        ans+=cnt
    # print(ans)
print(ans+(cnt*(cnt-1))//2)