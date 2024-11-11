n = int(input())
arr = list(map(int, input().split()))
arr1 = [0 for i in range(n)]
arr2 = [0 for i in range(n)]
#print(arr)
arr1[0] = arr[0]
for i in range(1,n):
    arr1[i] = arr[i] + arr1[i-1]
arr.sort()
#print(arr)
arr2[0] = arr[0]
for i in range(1,n):
    arr2[i] = arr[i] + arr2[i-1]
query = int(input())
#print(arr1)
#print(arr2)
for _ in range(query):
    t, l, r = map(int, input().split())
    if l == 1:
        if t == 1:
            print(arr1[r-1])
        else :
            print(arr2[r-1])
    else:
        if t == 1:
            print(arr1[r-1] - arr1[l-2])
        else :
            print(arr2[r-1] - arr2[l-2])