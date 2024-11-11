from itertools import combinations, permutations
from math import sqrt

EPS = 1e-6

def sd(x, y):
    return ((x[0] - y[0])**2 + (x[1] - y[1])**2)


def is_square(points):
    for perm in permutations(points):
        if sd(perm[0], perm[1]) == sd(perm[1], perm[2]) == \
                sd(perm[2], perm[3]) == sd(perm[3], perm[0]) and \
            sd(perm[0], perm[2]) == 2 * sd(perm[0], perm[1]) and \
            sd(perm[1], perm[3]) == 2 * sd(perm[0], perm[1]) and \
            sqrt(sd(perm[0], perm[1])) * sqrt(sd(perm[1], perm[2])) > EPS:
            return True
    return False

def is_rect(points):
    for perm in permutations(points):
        if sd(perm[0], perm[1]) == sd(perm[2], perm[3]) and \
            sd(perm[1], perm[2]) == sd(perm[3], perm[0]) and \
            sd(perm[0], perm[2]) == sd(perm[0], perm[1]) + sd(perm[1], perm[2]) and \
            sd(perm[1], perm[3]) == sd(perm[1], perm[2]) + sd(perm[2], perm[3]) and \
            sqrt(sd(perm[0], perm[1])) * sqrt(sd(perm[1], perm[2])) > EPS:
            return True
    return False

AMOUNT = 8
points = []
for _ in range(AMOUNT):
    points += [list(map(int, input().split()))]

found = False

to_choose = list(range(AMOUNT))
for for_square in combinations(to_choose, r=4):
    square, rect = [], []
    for i in range(AMOUNT):
        if i in for_square:
            square += [points[i]]
        else:
            rect += [points[i]]
    if is_square(square) and is_rect(rect):
        print("YES")
        print(' '.join(map(lambda x: str(x + 1), for_square)))
        print(' '.join(map(lambda x: str(x + 1), [y for y in range(AMOUNT) if y not in for_square])))
        found = True
        break

if not found:
    print("NO")