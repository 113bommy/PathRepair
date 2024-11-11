h1, a1, c1 = list(map(int, input().split()))
h2, a2 = list(map(int, input().split()))
out = []
b = 0

while h2 > 0:
    if h2 - a1 <= 0:
        h2 -= a1
        out.append("STRIKE")

    elif h1 - a2 <= 0:
        out.append("HEAL")
        h1 += c1

    else:
        h2 -= a1
        h1 -= a2
        out.append("STRIKE")

    b += 1

print(b)
[print(i) for i in out]