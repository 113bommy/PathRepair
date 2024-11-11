n,m = map(int,input().split())
l = []
s = []
a = []
for i in range(n):
    marks = input()
    s = [j for j in marks]
    l.append(s)
for i in range(m):
    l1 = []
    for j in range(n):
        l1.append(l[j][i])
    for k in range(n):
        if max(l1)==l[k][i]:
           a.append(k)
           break
        else:
           continue
print(len(set(a)))
