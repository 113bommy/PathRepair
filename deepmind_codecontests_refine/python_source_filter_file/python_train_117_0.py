import sys
import math
import cProfile

DEBUG = False
def log(s):
    if DEBUG and False:
        print(s)
        
def calc_dmg(num, arr):
    maximum = 0
    if num - len(arr) < 0:
        maximum = max(arr)
    return sum(arr) + maximum

if DEBUG:
    sys.stdin = open('input.txt')
    pr = cProfile.Profile()
    pr.enable()

n = sys.stdin.readline()
n = int(n)

dmg = [-sys.maxsize for _ in range(10)]

for i in range(n):
    log(dmg)
    cards = [_[:] for _ in [[-sys.maxsize] * 3] * 4]

    k = sys.stdin.readline()
    k = int(k)
    for _ in range(k):
        c, d = sys.stdin.readline().split()
        c = int(c)
        d = int(d)
        cards[c].append(d)
    cards[1].sort(reverse=True)
    cards[2].sort(reverse=True)
    cards[3].sort(reverse=True)
    log(cards)

    # dmg[j] = max(dmg[j],
    #              dmg[j - 1] + D(one card),
    #              dmg[j - 2] + D(two cards),
    #              dmg[j - 3] + D(three cards))
    # Plus, if 1 <= j <= 3, dmg[j] = max(dmg[j], D(cards))
    new_dmg = []
    for j in range(10):
        use1 = max(cards[1][0], cards[2][0], cards[3][0])
        use2 = max(cards[1][0] + cards[1][1],
                   cards[1][0] + cards[2][0])
        use3 = cards[1][0] + cards[1][1] + cards[1][2]

        maximum = 0
        if use1 > 0:
            maximum = max(maximum, dmg[j - 1] + calc_dmg(j, [use1]))
            if j == 1:
                maximum = max(maximum, use1)
        if use2 > 0:
            maximum = max(maximum, dmg[j - 2] +
                          calc_dmg(j, [cards[1][0], cards[1][1]]
                          if cards[1][0] + cards[1][1] == use2
                          else [cards[1][0], cards[2][0]]))
            if j == 2:
                maximum = max(maximum, use2)
        if use3 > 0:
            maximum = max(maximum, dmg[j - 3] +
                          calc_dmg(j, [cards[1][0], cards[1][1], cards[1][2]]))
            if j == 3:
                maximum = max(maximum, use3)
        new_dmg.append(maximum)
    dmg = new_dmg

log(dmg)
print(max(dmg))

if DEBUG:
    pr.disable()
    pr.print_stats()