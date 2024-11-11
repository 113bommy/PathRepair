n,k=map(int,input().split())
a=list(map(int,input().split()))
i=0
j=n-1
c=0
while i<j:
    if a[i]<=a[j] and a[i]<k:
        i+=1
        c+=1
    elif a[i]>a[j] and a[j]<k:
        j-=1
        c+=1
    else:
        break
print(c)