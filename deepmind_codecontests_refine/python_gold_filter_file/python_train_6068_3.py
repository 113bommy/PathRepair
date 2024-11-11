for w in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    x=-1
    p=-1
    ans=1
    k=n+1
    for i in range(n-1):
        if(a[i]>=a[i+1]):
            continue
        else:
            x=a[i]
            p=i+1
            a[i+1]-=x
            break
    for k in range(p+1,n):
        if(a[k]>=a[k-1] and a[k]-a[k-1]<=x):
            x=a[k]-a[k-1]
            a[k]=a[k-1]
        elif(a[k]>=a[k-1] ):
            a[k]-=x
        elif(a[k]<a[k-1]):
            break

    for j in range(k-1,n-1,1):
        if(a[j]<=a[j+1]):
            continue
        else:
            ans=0
            break
    if(ans==1 or x==-1):
        print("YES")
    else:
        print("NO")