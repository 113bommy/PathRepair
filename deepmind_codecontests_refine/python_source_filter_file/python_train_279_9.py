n, k = input().split(' ')
n = int(n)
k = int(k)
size = input().split(' ')
for i in range(n):
    size[i] = int(size[i])
size.sort()
count = n
j = 0
num = 0
for i in range(n):
    while size[i] > size[j] + k:
        j += 1
    if i == j:
        num = 0
    if size[i] > size[j]:
        count -= num
        j += 1
        num = 1
    else:
        num += 1
print(count)