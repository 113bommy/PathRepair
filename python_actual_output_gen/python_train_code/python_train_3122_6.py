a = list(input())
n = int(input())
b = []; p = []
if len(a) % n != 0: print("NO")
else:
    l = len(a) // n
    for i in range(l,len(a)+1,l):
        c = a[i-l:i]
        b.append(c)
for i in range(len(b)):
    for j in range(len(b[i])-1,-1,-1):
        p.append(b[i][j])
    if p != b[i]: print("NO"); exit()
    p = []
print("YES")