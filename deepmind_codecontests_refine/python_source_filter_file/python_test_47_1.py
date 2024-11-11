
for _ in range(int(input())):
    n,k=map(int, input().split())
    arr=list(map(int, input().split()))
    arr1,arr2=[],[]
    for x in arr:
        if x>-1:
            arr1.append(x)
        else:
            arr2.append(abs(x))
    arr1.sort(reverse=True)
    arr2.sort(reverse=True)
    ans=0
    if arr2 and arr1:
        if arr1[-1]>arr2[-1]:
            arr2,arr1=arr1,arr2
    for i in range(0,len(arr1),k):
        if i==0:
            if arr2:
                ans+=2*(arr1[i])
            else:
                ans+=arr1[i]
        else:
            ans+=2*(arr1[i])
    for i in range(0,len(arr2),k):
        if i==0:
            ans+=arr2[i]
        else:
            ans+=2*(arr2[i])
    print(ans)


