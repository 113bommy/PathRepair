def orac(n,arr,k):
    if(n==1 and arr[0]==k):
        return "yes"
    c=0
    d=0
    if(arr[n-1]==k):
        c=1
    for i in range(n-1):
        if(i==k):
            c=1
        if(min(arr[i],arr[i+1])>=k):
            d=1
        if(c==1 and d==1):
            break
    if(d==0):
        for i in range(n-2):
            l=[arr[i],arr[i+1],arr[i+2]]
            l.sort()
            if(min(l[1],l[2])>=k):
                d=1
                break
    if(d==1 and c==1):
        return "yes"
    return "no"
for i in range(int(input())):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    print(orac(n,arr,k))