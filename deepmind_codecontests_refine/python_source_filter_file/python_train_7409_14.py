
n, d = map(int, input().split())
array = list(map(int, input().split()))
res = 0
for i in range(1, len(array)):
    if array[i - 1] >= array[i]:
        res += (array[i - 1] - array[i]) // d + 1
        array[i] += (array[i - 1] - array[i]) // d + 1
print(res)
