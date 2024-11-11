t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    distinct=1
    for i in range(1,n):
        if arr[i]!=arr[i-1]:
            distinct+=1
    #print("d:",distinct)
    if k==1 and distinct>1:
        print(-1)
    elif distinct<=k:
        print(1)
    else:
        print(((distinct-k)//(k-1))+1)