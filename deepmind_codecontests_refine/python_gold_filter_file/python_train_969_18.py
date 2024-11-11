n=int(input())
arr=list(map(int,input().split()))
res=0
for i in range(1,n):
    f=0
    for j in range(i):
        if arr[i]<=arr[j]:
            f=1
            break
    if f==0:
        res+=1
for i in range(1,n):
    f=0
    for j in range(i):
        if arr[i]>=arr[j]:
            f=1
            break
    if f==0:
        res+=1
print(res)