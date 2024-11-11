N = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

x = 0
y = 0
for i in range(N):
    if a[i] > b[i]:
        x += (a[i] - b[i])
    elif a[i] < b[i]:
        y += (b[i] - a[i]) // 2

if x < y:
    print('Yes')
else:
    print('No')