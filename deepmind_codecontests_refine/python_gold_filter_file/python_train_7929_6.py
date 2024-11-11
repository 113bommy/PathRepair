n = int(input())
a = []
c = set()

s = input()
k = s.split(" ")
for f in range(len(k)):
    a.append(int(k[f]))
    c.add(a[f])
m = int(input())
b = []

s = input()
k = s.split(" ")
for f in range(len(k)):
    b.append(int(k[f]))
    c.add(b[f])

for i in range(n):
    f = False
    for j in range(m):
        k = a[i]+b[j]
        if not k in c:
            print(str(a[i])+" "+str(b[j]))
            f = True
            break
    if f:
        break