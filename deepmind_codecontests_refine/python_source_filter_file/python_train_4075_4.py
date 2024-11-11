count = int(input())
arr = [int(x) for x in input().split()]
a = max(arr)
b = 0
arr2 = set()
for i in range(len(arr)):
    if a % arr[i] != 0:
        arr2.add(arr[i])
    if arr.count(i) > 1:
        arr2.add(arr[i])
print(a, max(arr2))