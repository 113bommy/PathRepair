#!/usr/bin/env python3

import itertools

heroes = ["Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"]

n = int(input())
edges = []
for i in range(n):
  p,likes,q = input().split()
  edges.append((heroes.index(p), heroes.index(q)))
boss_xp = list(map(int, input().split()))

min_difference = float('inf')
max_liking = float('-inf')
for assignment in itertools.product(range(3), repeat=7):
  assignment_heroes = [[hero for (hero, boss) in enumerate(assignment) if (boss == i)] for i in range(3)]
  if any(len(attackers) == 0 for attackers in assignment_heroes):
    # Some bosses are not attacked at all
    continue

  xp_division = [xp / len(attackers) for (xp, attackers) in zip(boss_xp, assignment_heroes)]
  difference = max(xp_division) - min(xp_division)
  if (difference < min_difference):
    min_difference = difference
    max_liking = sum(len([(p,q) for (p,q) in edges if (p in attackers) and (q in attackers)]) for attackers in assignment_heroes)
  elif (difference == min_difference):
    liking = sum(len([(p,q) for (p,q) in edges if (p in attackers) and (q in attackers)]) for attackers in assignment_heroes)
    max_liking = max(max_liking, liking)

print("%d %d" % (min_difference, max_liking))