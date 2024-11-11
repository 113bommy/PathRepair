#!/usr/bin/env python3

xs = [int(x) for x in input().split()]

can = 1 in xs
can |= xs.count(2) == 2
can |= xs.count(2) == 1 and xs.count(4) == 2
can |= xs == [3, 3, 3]

print("YES" if can else "NO")
