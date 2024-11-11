n,k=list(map(int,input().split()))
defaultVal=k//n
for i in range(n):
    arr=[defaultVal]*n
    arr[i]=k-((n-1)*defaultVal)
    print(*arr)