x = input().split()
n = int(x[0])
h = int(x[1])
m = int(x[2])
proff = int(0)

arr = [0] * 50
for i in range(n):
    arr[i] = h

for i in range(m):
    a = input().split()
    k = [int(s) for s in a]
    s = k[0] - 1
    while s < k[1]:
        arr[s] = min(arr[k[0] - 1], k[2])
        s += 1

for q in range(n):
    proff += arr[q] ** 2

print(proff)
