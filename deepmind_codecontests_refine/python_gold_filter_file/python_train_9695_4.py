n=int(input())
arr=list(map(int,input().split()))
arr.sort()
c=0
for i in range(0,len(arr)-1,2):
    c+=arr[i+1]-arr[i]
print(c)