import operator
a = dict()
for i in range(int(input())):
    b = input()
    try:
        a[b] = i
    except KeyError:
        a[b] = 0
c = sorted(a.items(), key=operator.itemgetter(1),reverse=True)
d = []
for i in range(len(c)):
    d.append(c[i][0])
print(*d,sep='\n')