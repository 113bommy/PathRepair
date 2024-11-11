n = int(input())
a = [int(x) for x in input().split()]
m = int(input())
for i in range(m):
    temp = [int(x) for x in input().split()]
    x = temp[0]
    y = temp[1]
    if x-1 != 0:
        a[x-2] += y - 1
    if x-1 != m-1:
        a[x] += a[x-1] - y
    a[x-1] = 0
for x in a:
    print(x)
