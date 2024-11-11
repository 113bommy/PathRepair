from collections import Counter

n = int(input())
t = [int(i) for i in input().split()]
counter = Counter(t)
c = min(counter.values())
if len(counter) < 3:
    print(0)
else:
    print(c)
    skills = [1, 2, 3]
    grp_by_skill = []
    for s in skills:
        grp_by_skill.append([i for i in range(n) if t[i] == s])
    for i in range(c):
        print(f'{grp_by_skill[0][i]} {grp_by_skill[1][i]} {grp_by_skill[2][i]}')