N = int(input())

A = [int(x) for x in input().split()]

s = set()
god = 0
for a in A:
    if a >= 3200:
        god += 1
    else:
        s.add(a // 400)

print("{} {}".format(max(len(s),1), min(len(s) + god, 8)))
