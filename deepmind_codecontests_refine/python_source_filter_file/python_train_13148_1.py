from sys import stdin
input=stdin.readline
for _ in range(int(input())):
    n,u,v=map(int,input().split())
    arr=list(map(int,input().split()))
    ans=10**20
    for i in range(n-1):
        if arr[i]==arr[i+1]:
            ans=v+min(u,v)
        if abs(arr[i+1]-arr[i])>1:
            ans=0
        if abs(arr[i]-arr[i+1])==1:
            ans=min(ans,u,v)
    print(ans)
