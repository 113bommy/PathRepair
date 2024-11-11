t=int(input())
while t:
    t=t-1
    n=int(input())
    a=list(map(int,input().split()))
    cnt=0
    flag=0
    for i in range(1,n+1):
        if a[i-1]==i:
            flag=0
        else:
            if flag==0:
                cnt+=1
                flag=1
    print(cnt)