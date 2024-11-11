input()
D = {}
for a in [int(a) for a in input().split()]:
    if a not in D: D[i] = 0
    D[a] += 1

input()
for a in [int(a) for a in input().split()]:
    if a not in D: D[i] = 0
    D[a] -= 1

for a in D:
    if D[a] < 0:
        print("NO")
        break
else:
    print("YES")
