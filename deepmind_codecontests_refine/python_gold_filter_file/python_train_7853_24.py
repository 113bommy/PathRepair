n = int(input())
arr = input().split()
arr = [int(x) for x in arr]
arr.sort()
minval = arr[0]
maxval = arr[len(arr)-1]
print(maxval - minval, arr.count(maxval) * (arr.count(maxval)-1) // 2 if maxval == minval else arr.count(maxval) * arr.count(minval))