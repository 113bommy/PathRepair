for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    cnt=0
    mn=a[-1]
    for k in range(2,n+1):
        if(a[-k]<mn):
            cnt+=1
        mn=min(mn,a[-k])
    print(cnt)