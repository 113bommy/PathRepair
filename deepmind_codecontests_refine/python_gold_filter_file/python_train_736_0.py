n =int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
t = []
c = []
f = 0
for j in range(0 ,a[0]+b[0]+1):
        for l in range(0, a[0] + b[0]+1):
            if j|l == a[0] and j&l ==b[0]:
                t.append(j)
                t.append(l)
s = len(t)
if len(t)!=0 and n>2 :
    for i in range(s//2):
      if f == 1:
        break
      else:
        c =[]
        c.append(t[0])
        c.append(t[1])
        del(t[0])
        del(t[0])
        for j in range(1,n-1):
            f = 0
            for m in range(a[j]+b[j]+1):
                if c[j]|m == a[j] and c[j]&m == b[j]:
                    c.append(m)
                    f = 1
                    break
            if f!=1:
                break
else:
    f = 0
if f == 1:
    print('Yes')
    print(*c)
elif n ==2 and s>0:
    print('Yes')
    print(*t[:n])
elif f == 0:
    print('No')