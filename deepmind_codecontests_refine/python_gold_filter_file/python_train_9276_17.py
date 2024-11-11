n = int(input())
possibles = set(int(s) for s in input().split()[1:])
for i in range(n - 1):
    new = set(int(s) for s in input().split()[1:])
    possibles = set.intersection(possibles, new)
print(*possibles)
