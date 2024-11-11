from sys import stdin, exit
from bisect import bisect_left as bl, bisect_right as br

input = lambda: stdin.readline()[:-1]
intput = lambda: int(input())
sinput = lambda: input().split()
intsput = lambda: map(int, sinput())

def dprint(*args, **kwargs):
    if debugging:
        print(*args, **kwargs)


debugging = 1
# Code
n, m = intsput()

grid = []

for _ in range(n):
    grid.append(list(map(int, input())))

if n >= 4 and m >= 4:
    print(-1)
    exit(0)

if n == 1 or m == 1:
    print(0)
    exit(0)

if n == 2:
    odds_in_odds = 0
    evens_in_evens = 0

    for i in range(m):
        val = grid[0][i] + grid[1][i]
        if i % 2:
            if val % 2:
                odds_in_odds += 1
        else:
            if val % 2 == 0:
                evens_in_evens += 1
    
    changes = odds_in_odds + evens_in_evens
    ans = min(m - changes, changes)
    print(ans)
    exit(0)

if m == 2:
    odds_in_odds = 0
    evens_in_evens = 0

    for i in range(n):
        val = grid[i][0] + grid[i][1]
        if i % 2:
            if val % 2:
                odds_in_odds += 1
        else:
            if val % 2 == 0:
                evens_in_evens += 1
    
    changes = odds_in_odds + evens_in_evens
    ans = min(n - changes, changes)
    print(ans)
    exit(0)

if n == 3:
    odds_in_odds = set()
    evens_in_odds = set()
    odds_in_evens = set()
    evens_in_evens = set()

    for i in range(m):
        val = grid[0][i] + grid[1][i]
        if i % 2:
            if val % 2:
                odds_in_odds.add(i)
            else:
                evens_in_odds.add(i)
        else:
            if val % 2 == 0:
                evens_in_evens.add(i)
            else:
                odds_in_evens.add(i)
    

    odds_in_odds_ = 0
    t1_odd_extra_changes = 0

    evens_in_odds_ = 0
    t2_odd_extra_changes = 0

    evens_in_evens_ = 0
    t1_even_extra_changes = 0

    odds_in_evens_ = 0
    t2_even_extra_changes = 0

    for i in range(m):
        val = grid[1][i] + grid[2][i]
        if i % 2:
            if val % 2:
                odds_in_odds_ += 1
                if i not in odds_in_odds:
                    t1_odd_extra_changes += 1
            else:
                evens_in_odds_ += 1
                if i not in evens_in_odds:
                    t2_odd_extra_changes += 1
        else:
            if val % 2 == 0:
                evens_in_evens_ += 1
                if i not in evens_in_evens:
                    t1_even_extra_changes += 1
            else:
                odds_in_evens_ += 1
                if i not in odds_in_evens:
                    t2_even_extra_changes += 1
    
    a = len(odds_in_odds) + len(evens_in_evens) + t1_odd_extra_changes + t1_even_extra_changes
    b = len(odds_in_odds) + len(evens_in_evens) + evens_in_odds_ + odds_in_evens_ - t2_even_extra_changes - t2_odd_extra_changes
    c = m - len(odds_in_odds) - len(evens_in_evens) + t2_even_extra_changes + t2_odd_extra_changes
    d = m - len(odds_in_odds) - len(evens_in_evens) + odds_in_odds_ + evens_in_evens_ - t1_even_extra_changes - t1_even_extra_changes
    print(min(a, b, c, d))
    exit(0)
    

if m == 3:
    odds_in_odds = set()
    evens_in_odds = set()
    odds_in_evens = set()
    evens_in_evens = set()

    for i in range(n):
        val = grid[i][0] + grid[i][1]
        if i % 2:
            if val % 2:
                odds_in_odds.add(i)
            else:
                evens_in_odds.add(i)
        else:
            if val % 2 == 0:
                evens_in_evens.add(i)
            else:
                odds_in_evens.add(i)
    

    odds_in_odds_ = 0
    t1_odd_extra_changes = 0

    evens_in_odds_ = 0
    t2_odd_extra_changes = 0

    evens_in_evens_ = 0
    t1_even_extra_changes = 0

    odds_in_evens_ = 0
    t2_even_extra_changes = 0

    for i in range(n):
        val = grid[i][1] + grid[i][2]
        if i % 2:
            if val % 2:
                odds_in_odds_ += 1
                if i not in odds_in_odds:
                    t1_odd_extra_changes += 1
            else:
                evens_in_odds_ += 1
                if i not in evens_in_odds:
                    t2_odd_extra_changes += 1
        else:
            if val % 2 == 0:
                evens_in_evens_ += 1
                if i not in evens_in_evens:
                    t1_even_extra_changes += 1
            else:
                odds_in_evens_ += 1
                if i not in odds_in_evens:
                    t2_even_extra_changes += 1
    
    a = len(odds_in_odds) + len(evens_in_evens) + t1_odd_extra_changes + t1_even_extra_changes
    b = len(odds_in_odds) + len(evens_in_evens) + evens_in_odds_ + odds_in_evens_ - t2_even_extra_changes - t2_odd_extra_changes
    c = n - len(odds_in_odds) - len(evens_in_evens) + t2_even_extra_changes + t2_odd_extra_changes
    d = n - len(odds_in_odds) - len(evens_in_evens) + odds_in_odds_ + evens_in_evens_ - t1_even_extra_changes - t1_even_extra_changes
    print(min(a, b, c, d))
    exit(0)

raise Exception