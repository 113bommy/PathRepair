def bs(a,n,x):
    low=0
    high=n-1
    ans=-1
    while(low<=high):
        mid=(low+high)//2
        if(a[mid]==x):
            return mid 
        if(a[mid]<x):
            low=mid+1
        else:
            high=mid-1
    return ans
    
for t in range(int(input())):
    n,s,k=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    i=bs(l,k,s)
    if(i==-1):
        print(0)
    else:
        le,re=-1,-1
        lj=i-1
        c=1
        while(lj>0):
            if(l[lj]!=s-c):
                le=s-c
                break
            c+=1
            lj-=1
        rj=i+1
        c=1
        while(rj<k):
            if(l[rj]!=s+c):
                re=s+c
                break
            c+=1
            rj+=1
        if(re==-1 and k<n and l[k-1]<n):
            re=l[k-1]+1
        if(le==-1 and k<n and l[0]>1):
            le=l[0]-1
        if(le==-1 and re==-1):
            print(le)
        elif(le==-1):
            print(re-s)
        elif(re==-1):
            print(s-le)
        else:
            print(min(s-le,re-s))