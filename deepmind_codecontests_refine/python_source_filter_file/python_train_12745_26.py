string = input().split()
n = int(string[0])  # Всего страниц
p = int(string[1])  # Текущая страница
k = int(string[2])  # Отступы

if p - k > 1:
    print('<<', end=' ')

for i in range(k, 0, -1):
    if p - i > 0:
        print(p - i, end=' ')

print('(' + str(p) + ')', end=' ')

for i in range(1, k+1):
    if p + i <= n:
        print(p + i, end=' ')

if p + k <= n:
    print('>>', end=' ')
