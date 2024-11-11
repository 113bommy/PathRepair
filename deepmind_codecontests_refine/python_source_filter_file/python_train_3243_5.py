n, b, a = map(int, input().split())
s = map(int, input().split())

cb = b
ca = a

c = 0

for x in s:
    if x == 1 and cb > 0 and ca < a:
        c += 1
        ca += 1
        b -= 1
    elif x == 0 and ca > 0:
        ca -= 1
        c += 1
    elif cb > 0:
        cb -= 1
        c += 1
    elif ca > 0:
        ca -= 1
        c += 1

    if ca == 0 and cb == 0:
        break

print(c)