for _ in range(int(input())):
    n = int(input())
    a=list(map(int,input().split()))
    ans=0
    for j in range(29,-1,-1):
        cnt=0
        for i in range(n):
            if(a[i] >= (1 << j) and a[i] < (1<<(j+1))):
                cnt+=1
        ans+=cnt*(cnt-1)/2
    print(ans)