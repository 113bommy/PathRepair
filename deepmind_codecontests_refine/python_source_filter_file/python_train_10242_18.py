l = []
for i in range(3):
    l.append([int(x) for x in input().split()])

if (l[0][0] + l[0][1] + l[1][0]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")

if (l[0][0] + l[0][1] + l[1][1] + l[0][2]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")

if (l[0][1] + l[0][2] + l[1][2]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")
print()

if (l[0][0] + l[2][0] + l[1][1] + l[0][1]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")

if (l[1][0] + l[0][1] + l[1][2] + l[2][1] + l[1][1]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")

if (l[1][1] + l[0][2] + l[1][2] + l[2][2]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")
print()

if (l[2][0] + l[1][0] + l[2][1]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")
if (l[2][0] + l[2][1] + l[2][2] + l[1][1]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")
if (l[2][2] + l[2][1] + l[1][2]) % 2 == 1:
    print(0, end = "")
else:
    print(1, end = "")