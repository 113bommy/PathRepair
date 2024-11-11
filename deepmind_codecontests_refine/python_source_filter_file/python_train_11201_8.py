c = True
ok, e = 0, 0

for _ in range(int(input())):
    a, b = map(int, input().split())
    if _ == 0:
        ok = a

    if b - a > 0:
        e += 1

    if _ != 0:
        c = (c and ok - a >= 0)
        ok = a

if e != 0:
    print("rated")
elif c:
    print("maybe")
else:
    print("unrated")        