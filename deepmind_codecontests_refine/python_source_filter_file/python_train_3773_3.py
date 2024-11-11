t=int(input())
ans=[]
for s in range(t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    arr.sort()
    copy=[]
    l=0
    r=n-1
    c=1
    while l<=r:
        if c%2!=0:
            copy.append(arr[r])
            r=r-1
        elif c%2==0:
            copy.append(arr[l])
            l=l+1
        c+=1
    copy.reverse()
    ans.append(copy)
for row in ans:
    print(row, sep=" ")



