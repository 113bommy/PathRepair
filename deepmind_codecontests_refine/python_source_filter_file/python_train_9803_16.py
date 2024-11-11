n=int(input())
z=1
arr=[0 for _ in range(n+1)]
for i in range(2,n+1):
    if arr[i]==0:
        arr[i]=z
        j=i*i
        while j<n+1:
            arr[j]=1
            j+=i
        z+=1
for k in range(2,n+1):
    print(arr[k],end=" ")
