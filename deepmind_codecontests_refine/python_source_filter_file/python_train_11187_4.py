n, k = input().split()
list_ = input()
mass = []
result = []
s = 0

n = int(n)
k = int(k)
k_1 = k
summ = ''
i = 0
while i < (len(list_)):
    if list_[i] == ' ':
        mass.append(int(summ))
        summ = ''
    else:
        summ = summ + list_[i]
        if i == len(list_) - 1:
            mass.append(int(summ))
    i = i + 1

i = 0
index_max = 0
index_men = 0
while i < k:
    max = mass[0]
    men = mass[0]
    for j in range(len(mass)):
        if mass[j] > max:
            max = mass[j]
            index_max = j
        if mass[j] < men:
            men = mass[j]
            index_men = j
    if max - men <= 1:
        break
    else:
        mass[index_max] = mass[index_max] - 1
        mass[index_men] = mass[index_men] + 1
        result.append(index_max + 1)
        result.append(index_men + 1)
    k = k - 1
max = mass[0]
men = mass[0]
for j in range(len(mass)):
    if mass[j] > max:
        max = mass[j]
        index_max = j
    if mass[j] < men:
        men = mass[j]
        index_men = j
s = max - men
k_1 = k_1 - k
print(s, k_1)

while True:
    if len(result) > 0:
        print(result.pop(0), result.pop(0))
    else:
        break