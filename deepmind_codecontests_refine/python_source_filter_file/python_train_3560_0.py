n,c=list(map(int,input().strip().split()))
a=list(map(int,input().strip().split()))
b=list(map(int,input().strip().split()))
arr=[[0,2] for i in range(n+2)]
op=[0]*(n)
for i in range(1,n):
    # print(a[i-1],b[i-1])
    arr[i][0]=min(arr[i-1][0]+a[i-1],arr[i-1][1]+a[i-1])
    arr[i][1]=min(arr[i-1][1]+b[i-1],arr[i-1][0]+b[i-1]+c)
    op[i]=min(arr[i])
# print(arr)
print(" ".join(list(map(str,op))))