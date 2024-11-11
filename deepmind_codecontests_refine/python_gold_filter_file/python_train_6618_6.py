from collections import Counter

name = input()
n = int(input())

cnt = Counter()
points = {'posted': 15, 'commented': 10, 'likes': 5}
for _ in range(n):
    action = input().split()
    subj = action[0]
    dest = action[3] if len(action) == 5 else action[2]
    dest = dest[:-2]

    p = points[action[1]]
    if subj == name:
        cnt[dest] += p
    elif dest == name:
        cnt[subj] += p
    else:
        cnt[subj] += 0
        cnt[dest] += 0


ans = sorted(((v, k) for k, v in cnt.items()), key = lambda x: (-x[0], x[1]))
print('\n'.join(x[1] for x in ans))
