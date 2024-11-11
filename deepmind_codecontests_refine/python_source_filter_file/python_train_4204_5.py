n = int(input())
arr = list(map(int, input().split()))
res = 0
for i in range(len(arr)):
    c = 0
    for j in range(len(arr)):
        c ^= arr[j]
        res = max(res, c)
print(res)
