for _ in range(int(input())):
    n,m = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    cnt = [0 for i in range(n)]
    for i in range(1,n-1):
        if arr[i]>arr[i+1] and arr[i]>arr[i-1]:
            cnt[i] = 1
    ans = 0
    idx = 1
    for i in range(1,m-1):
        if cnt[i]==1:
            ans+=1
    sh = ans
    for i in range(1,n-m+1):
        if(cnt[i]==1):
            sh-=1
        if cnt[i+m-2]==1:
            sh+=1
        if sh>ans:
            ans = sh
            idx+=1
    print(ans+1,idx)