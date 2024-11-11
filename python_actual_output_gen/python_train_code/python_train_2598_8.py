import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
for _ in range(int(input())):
    n=int(input())
    arr=[int(x) for x in input().split()]
    ans=n+n-1
    for i in range(n-2):
        if (arr[i]-arr[i+1])*(arr[i+1]-arr[i+2])<1:
            ans+=1
    for i in range(n-3):
        if ((arr[i+1]-arr[i+3])*(arr[i+3]-arr[i+2]) > 0 and (arr[i+1]-arr[i])*(arr[i]-arr[i+2]) > 0):
            ans+=1
    print(ans)