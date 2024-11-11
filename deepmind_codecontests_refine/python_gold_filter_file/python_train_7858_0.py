n = int(input())
a = list(map(int,input().split()))
m = -1;c = 0
if(n==1) :
    print(1)
else :
    for i in range(1,n) :
        if(a[i]>=a[i-1]) :
            c += 1
            m = max(c,m)
        else :
            c = 0
    if(m==-1) :
        print(1)
    else :
        print(m+1)