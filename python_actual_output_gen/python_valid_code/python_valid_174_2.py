n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

change = 0
i = 0
while i < k and i < n:
    if arr[i] < 0:
        arr[i] = -arr[i]
    else:
        break
    i = i + 1

k = k - i
if k > 0 and k % 2 == 0:
    arr.sort()
    arr[0] = -arr[0]

print(sum(arr))
