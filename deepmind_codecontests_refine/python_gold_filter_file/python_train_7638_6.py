#B. Polo the Penguin and Matrix
n,m,d = map(int,input().split())
a = []
b = []
for i in range(n):
    tmp = list(map(int,input().split()))
    a.append(tmp)
    b = b + tmp
flag = True
x = a[0][0]%d
for i in range(n):
    for j in range(m):
        if a[i][j]%d!=x:
            flag = False
            break
b.sort()
k = len(b)
k = (k//2)
s = 0
for i in b:
    s += abs(i-b[k])
s /= d
if flag:
    print(int(s))
else:
    print(-1)