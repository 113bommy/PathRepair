h1, a1, c1 = map(int, input().split())
h2, a2 = map(int, input().split())
m = []
while h2 >= 0:
    if h2 <= a1:
        m.append('STRIKE')
        h2 -= a1
    elif a2 >= h1:
        m.append('HEAL')
        h1 += c1
        h1 -= a2
    else:
        m.append('STRIKE')
        h2 -= a1
        if h2 <= 0:
            break
        h1 -= a2
print(len(m))
for i in range(len(m)):
    print(m[i])