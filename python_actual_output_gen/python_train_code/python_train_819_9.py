n,k=map(int,input().split())
a=list(map(int,input().split()))
count=sum=i=0
while i<n:
    if sum+a[i]>k:
        break
    sum+=a[i]
    i+=1
c=i
j=i
print('j = ',j,' c = ',c)
while j<n:
    count+=1
    sum+=a[j]-a[count-1]
    if sum<k:
        j+=1
        if j>=n:
            break
        while sum+a[j]<=k:
            sum+=a[j]
            c+=1
            j+=1
            if j>=n:
                break
    else:
        j+=1
print(c)
        
