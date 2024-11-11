def countSort(list1):
    support = [0]*1000
    result = []
    for element in list1:
        support[element] += 1

    for i, element in enumerate(support):
        if element > 0:
            for _ in range(element):
                result.append(i)
    return result

n, m = int(input()), int(input())
a = []

for i in range(n):
    a.append(int(input()))

a = countSort(a)
s = 0
c = 0

while s < m:
    s += a[c]
    c += 1

print(c)