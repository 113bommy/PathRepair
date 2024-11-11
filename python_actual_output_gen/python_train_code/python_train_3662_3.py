n=int(input())
a = list(map(int,input().strip().split()))[:n]
arr=[]
for i in range(0,n):
    arr.append(1)
for i in range(1,n):
    for j in range(0,n):
        if a[j]<a[i]:
            arr[j]+=1
print(*arr, sep =' ')