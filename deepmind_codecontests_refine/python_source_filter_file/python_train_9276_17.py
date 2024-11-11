n = int(input())
possibles = set(int(s) for s in input().split())
for i in range(n - 1):
    new = set(int(s) for s in input().split())
    possibles = set.intersection(possibles, new)
print(*possibles)
