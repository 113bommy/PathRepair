#!/usr/bin/env python3

def is_lucky(v):
    while v > 0:
        r = v % 10
        if r != 4 and r != 7:
            return False
        v //= 10
    return True


n = int(input())
arr = list(map(int, input().split()))
arr_with_pos = sorted([[a, i] for i, a in enumerate(arr)])

pos, tpos = None, None  # pos and target pos for one of the lucky numbers
not_ordered = set()
need = [i for _, i in arr_with_pos]
belong = [0] * n
for i in range(n):
    belong[need[i]] = i

for i in range(n):
    a, opos = arr_with_pos[i]
    if pos is None and is_lucky(a):
        pos, tpos = opos, i
    if opos != i:
        not_ordered.add(opos)

if pos is None:
    ordered = True
    for i in range(n):
        if arr[i] != arr_with_pos[i][0]:
            ordered = False
            break
    print(0 if ordered else -1)
else:
    ans = []
    while not_ordered:
        if pos == tpos:
            for first in not_ordered:
                break
            if first == tpos:
                not_ordered.discard(first)
                continue
            ans.append([pos, first])
            need[pos] = first
            belong[pos] = belong[first]
            need[belong[first]] = pos
            belong[first] = tpos
            pos = first
        else:
            ans.append([need[pos], pos])
            not_ordered.discard(pos)
            pos = need[pos]
            need[tpos] = pos
            belong[pos] = tpos

    print(len(ans))
    for p1, p2 in ans:
        print(p1, p2)
