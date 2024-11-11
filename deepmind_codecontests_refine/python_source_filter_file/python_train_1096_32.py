n = int(input())
arr = list(map(int, input().split()))
minimum = n + 1
maximum = 1 - 1
indexMax = -1
indexMin = -1
k = n // 2
for i in range(k):
    if arr[i] > maximum:
        maximum = arr[i]
        indexMax = i
    if arr[i] < minimum:
        minimum = arr[i]
        indexMin = i
    if arr[n - 1 - i] > maximum:
        maximum = arr[n - 1 - i]
        indexMax = n - 1 - i
    if arr[n - 1 - i] < minimum:
        minimum = arr[n - 1 - i]
        indexMin = n - 1 - i

if k % 2 != 0:
    if arr[k] > maximum:
        maximum = arr[k]
        indexMax = k
    if arr[k] < minimum:
        minimum = arr[k]
        indexMin = k

left = min(indexMin, indexMax)
right = max(indexMin, indexMax)

if n - 1 - left > right:
    print(n - 1 - left)
else:
    print(right)