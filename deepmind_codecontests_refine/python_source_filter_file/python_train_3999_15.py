n = int(input())
groups = 0
magnets = []
for _ in range(n):
    magnets.append(input())

for m in range(n - 1):
    if magnets[m][-1] == magnets[m + 1][1]:
        groups += 1

print(groups)