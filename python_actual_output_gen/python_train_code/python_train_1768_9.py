n,h=map(int,input().split())
ar=[int(x) for x in input().split()]
arr=[ar[0]]
ans=0
for k in range(1,n):
    for p in range(len(arr)):
        flag=True
        if ar[k]>=arr[p]:
            arr.insert(p,ar[k])
            flag=False
            break
    if flag:
        arr.append(ar[k])

    temp=0
    for p in range(0,len(arr),2):
        temp+=arr[p]
    if temp<=h:
        ans=len(arr)
print(ans)
            
            
   
