n=int(input())
arr=list(map(int,input().split()))
arr.sort()
c=0
for i in range(len(arr)-1):
    c+=arr[i+1]-arr[i]
print(c)