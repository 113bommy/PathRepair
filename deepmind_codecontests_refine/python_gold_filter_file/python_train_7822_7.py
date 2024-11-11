n=int(input())
arr=[int(x) for x in input().split()]
ans=''
i=0
j=n-1
last=0
while i<=j:
    if arr[i]>last and arr[j]>last:
        if arr[i]>arr[j]:
            ans+='R'
            last=arr[j]
            j-=1
        else:
            ans+='L'
            last=arr[i]
            i+=1
    elif arr[i]>last:
        ans+='L'
        last=arr[i]
        i+=1
    elif arr[j]>last:
        ans+='R'
        last=arr[j]
        j-=1
    else:
        break
print(len(ans))
print(ans)