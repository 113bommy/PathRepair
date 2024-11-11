for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    i=0
    j=n-1
    p=0
    k=[]
    while i<n-1 and j>i:
        if a[i]>=a[j]:
            if len(k)==0 or a[j]>=k[-1] :
                k.append(a[j])
                j-=1
            elif a[j]<k[-1]:
                k=[]
                i=j
                p=i
                j=n-1
                continue
        else:
            if len(k)==0 or a[i]>=k[-1] :
                k.append(a[i])
                i+=1
            elif a[i]<k[-1]:
                k=[]
                p=i
                j=n-1
                continue
    else:
        print(p)