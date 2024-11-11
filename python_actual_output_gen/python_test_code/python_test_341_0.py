n,a,b=map(int,input().split())

arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))

ans=[2]*n

for i in range(a):
    ans[arr1[i]-1]=1

print(ans)

