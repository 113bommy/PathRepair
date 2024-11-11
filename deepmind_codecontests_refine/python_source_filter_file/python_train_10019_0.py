for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    ind=[0]*n
    for i in range(n):
        ind[a[i]-1]=i
    c=[1]*n
    flag=1
    for i in range(n):
        t=c[ind[i]]
        c[ind[i]]=-1
        if(ind[i]<n-1 and c[ind[i]+1]!=-1):
            c[ind[i]+1]+=t
            if(ind[i+1]!=ind[i]+1):
                print(c)
                flag=0
                break
        # print(c)
        
    if(flag==0):
        print('No')
    else:
        print('Yes')