def f(x):
    curr=0
    for i in range(n):
        if(curr>=m):
            return 0
        if(x<m-arr[i]):
            if(arr[i]+x<curr):
                return 0
            curr=max(curr,arr[i])
        else:
            start=(x+arr[i])%m
            if(curr>start):
                curr=max(curr,arr[i])
    return 1
def binary_search(l,r):
    mid=(l+r)//2
    if(mid==l):
        return mid
    if(f(mid)):
        if(f(mid-1)==0):
            return mid
        return binary_search(l,mid-1)
    return binary_search(mid+1,r)
l=input().split()
n=int(l[0])
m=int(l[1])
l=input().split()
arr=[int(i) for i in l]
print(binary_search(0,m-1))