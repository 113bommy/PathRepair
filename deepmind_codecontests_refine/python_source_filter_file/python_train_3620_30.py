from collections import defaultdict

n = int(input())
line = defaultdict(list)  # R,L
row = defaultdict(list)  # U,D
A = defaultdict(list)  # U,R
B = defaultdict(list)  # L,D
C = defaultdict(list)  # U,L
D = defaultdict(list)  # R,D

for i in range(n):
    x, y, u = input().split()
    x = int(x)
    y = int(y)
    if u == "U":
        row[x].append((y, u == "U"))
        A[y + x].append((y - x, u == "U"))
        C[y - x].append((y + x, u == "U"))
    elif u == "D":
        row[x].append((y, u == "U"))
        B[y + x].append((y - x, u == "L"))
        D[y - x].append((y + x, u == "R"))
    elif u == "L":
        line[y].append((x, u == "R"))
        B[y + x].append((y - x, u == "L"))
        D[y - x].append((y + x, u == "R"))
    else:
        line[y].append((x, u == "R"))
        A[y + x].append((y - x, u == "U"))
        C[y - x].append((y + x, u == "U"))

ans = 10**18
for Z in (line, row, A, B, C, D):
    for z_list in Z.values():
        z_list.sort()
        for (v1, flag1), (v2, flag2) in zip(z_list, z_list[1:]):
            if flag1 and not flag2:
                ans = min(ans, abs(v1 - v2) * 5)

if ans == 10**18:
    print("SAFE")
else:
    print(ans)
