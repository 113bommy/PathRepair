n, d = map(int, input().split())
jump = []
if d != 0:
    jump = sorted(list(map(int, input().split())))

if d == 0:
    print("YES")
    exit()

if jump[0] == 1 or jump[len(jump)-1] == n:
    print("NO")
    exit()

if d == 1 or d == 2:
    print("YES")
    exit()

for i in range(d-2):
    if jump[i+1]-jump[i] == 1 and jump[i+2]-jump[i] == 2:
        print("NO")
        exit()

print("YES")




