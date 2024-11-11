n = int(input())
lst = []
d = {}
for i in range(n):
    a,b = input().split()
    b = int(b)
    lst.append([a,b])
    if a in d:
        d[a] += b
    else:
        d[a] = b
max1 = - 1000001
for i in d.values():
    if i > max1:
        max1 = i
b = set()
for i in d.keys():
    if d[i] == max1:
        b.add(i)
d = {}
for i,j in lst:
    if i in d:
        d[i] += j
    else:
        d[i] = j
    if d[i] == max1 and i in b:
        print(i)
        break
