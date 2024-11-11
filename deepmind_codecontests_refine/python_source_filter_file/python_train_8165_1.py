# Входные данные
input()
a = [int(a_i) for a_i in input().split()]
# a = [i % 10000 for i in range(100000)]
n = len(a)

# Записываем данные в словарь
count = {}
for number in a:
    if number not in count:
        count[number] = 1
    else:
        count[number] += 1
c_list = list(count.items())

f = []

# Решаем задачу
for i, (first, second) in enumerate(c_list):
    pr = i - 1
    while pr >= 0 and c_list[pr][0] + 1 == c_list[i][0]:
        pr -= 1
    if pr == -1:
        f.append(c_list[i][0] * c_list[i][1])
    else:
        f.append(c_list[i][0] * c_list[i][1] + f[pr])
    if i != 0:
        f[i] = max(f[i], f[i-1])

print(f[-1])