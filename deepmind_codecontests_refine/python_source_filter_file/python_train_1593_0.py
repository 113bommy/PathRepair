import sys

#First solution
"""
for _ in range(int(input())):
    n = int(input())
    s = set()
    x = list(map(int, input().split()))
    for i in x:
        if i in s and i + 1 not in s:
            s.add(i + 1)
        s.add(i)
    print(len(s))
"""
#Second solution
"""
for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    x.sort()
    changed = 0
    for i in range(n):
        if x[i] == x[i - 1]:
            x[i] += 1
            changed = x[i]
        else:
            if changed == x[i]:
                x[i] += 1
    print(len(set(x)))
"""
#Third solution

for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    for i in range(n):
        if x[i] <= x[i - 1]:
            x[i] += 1
    print(len(set(x)))

#Fourth solution
"""
for _ in range(int(input())):
    n = int(input())
    s = set()
    for i in map(int, input().split()):
        if i in s:
            i += 1
        s.add(i)
    print(len(s))
"""
