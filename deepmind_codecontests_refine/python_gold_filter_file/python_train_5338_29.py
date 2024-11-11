n=int(input())
a=sorted(list(map(int,input().split())))
arr=[0]*n
i=0
for j in range(n//2,n):
    arr[i]=a[j]
    i+=2
    
i=1    
for j in range(n//2):
    arr[i]=a[j]
    i+=2

cnt=0
for i in range(1,n-1):
    if arr[i-1]>arr[i]<arr[i+1]:cnt+=1


print(cnt)
print(*arr)