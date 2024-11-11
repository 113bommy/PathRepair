n = int(input())

lst = []
for x in range(n):
    lst.append([])
for x in range(n):
    spisok = list(map(int, input().split()))
    lst[x] = spisok

a = []

if n != 1:
    for x in range(n - 1):
        for y in range(x + 1, n):
          for i in lst[x]:
              for z in lst[y]:
                  a.append(int(str(i) + str(z)))
                  a.append(int(str(z) + str(i)))

b = []
if n == 3:
    for x in range(len(a)):
        if x < 72:
            for y in lst[2]:
                b.append(int(str(a[x]) + str(y)))
                b.append(int(str(y) + str(a[x])))
        elif x < 144 and x >= 72:
            for y in lst[1]:
                b.append(int(str(a[x]) + str(y)))
                b.append(int(str(y) + str(a[x])))
        else:
            for y in lst[0]:
                b.append(int(str(a[x]) + str(y)))
                b.append(int(str(y) + str(a[x])))

for x in range(n):
    for y in lst[x]:
        a.append(y)

a += b
        
a = set(a)
t = True
k = 1
while t:
    if k in a:
        k += 1
    else:
        t = False
print(k - 1)
