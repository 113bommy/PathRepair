h1, a1, c1 = list(map(int, input().split()))
h2, a2 = list(map(int, input().split()))
n = 0
a = []
while h2 > 0:
    if h1 > a2 or h2 < a1:
        h2 -= a1
        a.append("STRIKE")
    else:
        h1 += c1
        a.append("HEAL")
    h1 -= a2
    n += 1
print(n)
for i in range(n):
    print(a[i])
    
