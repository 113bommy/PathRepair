def series():
    ls = []
    j = 0
    while len(ls) <= 1000:
        if j % 3 != 0 and j % 10 != 3:
            ls.append(j)
        j += 1
    return ls


n = int(input())
lst1 = []
for i in range(n):
    k = int(input())
    lst1.append(k)
lis = series()
for i in range(n):
    m = lis[lst1[i-1]]
    print(m)