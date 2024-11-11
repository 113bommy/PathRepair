def jewel(lst, n):
    sum_x, sum_y = 0, 0
    for elem in lst:
        sum_x += elem[0]
        sum_y += elem[1]
    return sum_x // n, sum_y // n


N = int(input())
a = list()
for i in range(N):
    x, y = [int(j) for j in input().split()]
    a.append([x, y])
print(*jewel(a, N))
