n, m = map(int, input().split())

l = [input() for i in range(n)]
print(l)
l1 = [j for i in range(n) for j in range(m) if l[i][j] == '*']
l2 = [i for i in range(n) for j in range(m) if l[i][j] == '*']

mi1, ma1 = min(l1), max(l1)+1
mi2, ma2 = min(l2), max(l2)+1

for i in range(mi2, ma2):
    print(l[i][mi1:ma1])
