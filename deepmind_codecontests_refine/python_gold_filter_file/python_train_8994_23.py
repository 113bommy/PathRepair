n, m = map(int, input().split())

if m > 0:
    stairs = [int(z) for z in input().split()]

    stairs.sort()
else:
    print("YES")
    exit()

if m < 3 and stairs[-1] != n and stairs[0] != 1:
    print("YES")
    exit()

if stairs[-1] == n or stairs[0] == 1:
    print("NO")
    exit()

for x in range(m - 2):
    if stairs[x] == stairs[x + 1] - 1:
        if stairs[x + 1] == stairs[x + 2] - 1:
            print("NO")
            exit()

print("YES")

