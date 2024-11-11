n = int(input())
arr = list(map(float, input().split()))
arr = sorted([x - int(x) for x in arr if x - int(x) != 0])
o = 2 * n - len(arr)
arr_sum = sum(arr)
res = int(2e9)
for i in range(n + 1):
    if i + o >= n:
        res = min(res, abs(i - arr_sum))
print(res)
