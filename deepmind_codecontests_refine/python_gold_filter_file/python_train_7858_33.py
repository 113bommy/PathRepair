n = int(input())
a = list(map(int, input().split()))
count = 0

prev = a[0]
count = 1
max_length = 1
for i in range(1, n):
    if a[i] >= prev:
        count += 1
    else:
        count = 1
    prev = a[i]
    max_length = max(max_length, count)
print(max_length)