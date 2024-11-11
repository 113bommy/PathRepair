n = int(input())
mas = [int(0) for i in range(102)]
maxx = 0
cnt = 0
res = []
for i in range(n):
    m = [int(j) for j in input().split()]
    for j in range(1, len(m)):
        mas[m[j]] += 1
        if (mas[m[j]] > maxx):
            maxx = mas[m[j]]
for i in range(len(mas)):
    if (mas[i] == maxx):
        res.append(i)
print(*res)
