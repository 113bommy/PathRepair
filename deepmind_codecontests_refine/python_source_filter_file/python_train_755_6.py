t=int(input())
while(t>0):
    t=t-1
    n=int(input())
    a=input().split()
    for i in range(0,n):
        a[i]=int(a[i])
    b=set(a)
    if(len(b)==1):
        print(-1)
    else:
        k=max(a)
        index=-1
        for i in range(0,n-1):
            if((a[i]==k)&(a[i+1]<a[i])):
                index=i
                break
        if(index==-1):
            for i in range(1,n):
                if((a[i]==k)&(a[i]>a[i-1])):
                    index=i
                    break
        print(index)