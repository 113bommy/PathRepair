t = int(input())
angles = []
for i in range(3,181):
    a = (i-2)*180
    a = a/i
    if int(a) == a:
        angles.append(a)
for test in range(t):
    n = int(input())
    if n in angles:
        print("YES")
    else:
        print("NO")