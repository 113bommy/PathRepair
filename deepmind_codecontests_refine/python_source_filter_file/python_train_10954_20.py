n=int(input())
arr=list(map(int,input().split()))
arr1=[0]*(400002)
for i in range(n):
 m=arr[i]-(i+1)
 arr1[m]+=arr[i]
print(max(arr1))
