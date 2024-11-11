n = int(input())
arr = list(map(int, input().split()))
arr.sort()
count = []
for k in range(n - 1):
    count.append(arr[k+1]-arr[k])
zz = min(count)
print(zz, arr.count(zz))