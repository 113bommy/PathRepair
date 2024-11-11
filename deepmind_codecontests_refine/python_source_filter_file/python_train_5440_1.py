n, p = map(int, input().split())
arr = list(map(int, input().split()))
l, r = 0, float('inf')
arr.sort()
for i in range(len(arr)):
    l = max(l, arr[i]-i)
    if i+1 >= p:
        r = min(r, arr[i]-i+p-1)
print(max(0,l-r))
res = []
for i in range(l,r):
    res.append(i)
print(*res)