n = int(input())
arr1 = list(map(int,input().strip().split()))[:n]
arr2 = list(map(int,input().strip().split()))[:n-1]
arr3 = list(map(int,input().strip().split()))[:n-2]
print(sum(arr1)-sum(arr2))
print(sum(arr3)-sum(arr2))