a = [[[0 for z in range(10)] for y in range(3)] for x in range(4)]
n = int(input())
for i in range(n):
    b, f, r, v = [int(x) for x in input().split()]
    a[b - 1][f - 1][r - 1] += v

for i in range(4):
    for j in range(3):
        print('', *a[i][j])
    if i != 3:
        print('#' * 20)