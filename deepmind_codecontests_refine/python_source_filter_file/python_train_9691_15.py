n,d=map(int,input().split())
arr=[int(i) for i in input().split()]
ans=0
for i in range(1,n):
    if (arr[i]-arr[i-1]==2*d):
        ++ans
    elif (arr[i]-arr[i-1]>2*d):
        ans+=2
print(ans+2)
