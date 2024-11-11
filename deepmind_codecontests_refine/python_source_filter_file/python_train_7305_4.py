t=int(input())
for i in range(t):
    n,a,b=map(int,input().split())
    s=input()
    arr = [[10**10 for i in range(2)] for j in range(n+1)] 
    arr[0][0]=b
    for i in range(1,n+1):
        if s[i-1]=="0":
            arr[i][1]=min(arr[i-1][1]+2*b+a,arr[i-1][0]+2*b+2*a)
            arr[i][0]=min(arr[i-1][1]+2*a+b,arr[i-1][0]+a+b)
        else:
            arr[i][1]=arr[i-1][1]+2*b+a
    print(arr[n][0])
    