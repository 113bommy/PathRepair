n, m, k = [int(i) for i in input().split()]
schools = [[] for i in range(m)]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
res = 0
for i, j in list(zip(a, b)):
    schools[j-1] += [i]
for c in x:
    i = a[c-1]
    j = b[c-1]
    if i == max(schools[j-1]):
        res += 1
        schools[j-1].remove(i)


print(res)
