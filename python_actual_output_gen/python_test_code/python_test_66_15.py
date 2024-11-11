NONE = 10 ** 10

n = int(input())
direct = input()
pos = [int(x) for x in input().split()]

best = NONE
for i,x in enumerate(pos):
    if i+1 == n:
        break
    if direct[i:2] != 'RL':
        continue

    best = min(best, pos[i+1] - x)

if best == NONE:
    best = -1
else:
    best = best // 2

print(best)
