n, m = map(int,input().split())
I = []
for i in range(n):
    I.append(i+1)
for i in range(m):
    a, b = map(int,input().split())
    if a in I:
        I.remove(a)
    if b in I:
        I.remove(b)
f = I[0]
print(n-1)
for i in range(n-1):
    if i+1 != n:
        print(n,i+1)