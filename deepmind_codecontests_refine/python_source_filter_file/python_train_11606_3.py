n = int(input())
a = []
a.append([1] * n)  # Добавляем в первую строку единицы
for i in range(n - 1):
    a.append([1] + [0] * (n - 1))
max = 0
for i in range(1,n):
    for j in range(1,n):
        a[i][j] = a[i-1][j] + a[i][j-1]
        if a[i][j] > max:
            max = a[i][j]
# for i in a:
#     print(*i)
print(max)
