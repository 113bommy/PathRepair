def bsearch(arr,target):
    start =0
    end = len(arr)-1
    while(start<=end):
        mid = ((start+end)//2)
        if target>arr[mid]:
            start=mid+1
        elif target<arr[mid]:
            end = mid -1
        else:
            return mid
    return start
n = int(input())
a1 = list(map(int,input().split()))
m = int(input())
a2 = list(map(int,input().split()))
r = []
s=0
for i in range(n):
    s+=a1[i]
    r.append(s)
print(r)
for i in a2:
    print(bsearch(r,i)+1)