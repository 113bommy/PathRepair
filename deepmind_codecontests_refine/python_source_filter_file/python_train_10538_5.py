
n,m,k=map(int,input().split())
ls=list(map(int,input().split()))
arr=list(map(int,input().split()))
for i in range(len(ls)):
    if arr[i]%k!=0:
        x=i
        break
for j in range(len(arr)):
    if arr[j]%k!=0:
        y=j
        break
print(x+y)