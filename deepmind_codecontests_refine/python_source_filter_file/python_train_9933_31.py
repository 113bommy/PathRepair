n, k = list(map(int, input().split(" ")))
array = list(map(int, input().split(" ")))
current = 0
index = 1

for i in range(0, k):
    current += array[i]

min = current

for i in range(k, n):
    current += array[k]
    current -= array[i - k]
    if current < min:
        min = current
        index = i - k + 1
print(index)
