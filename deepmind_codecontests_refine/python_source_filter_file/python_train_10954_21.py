n=int(input())
arr=list(map(int,input().split()))
arr1=[0]*(400005)
for i in range(n):
 m=arr[i]-(i+1)
 arr1[m]+=arr[i]
print(max(arr1))
