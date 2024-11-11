n, k = (int(i) for i in input().split())
actions = [int(i) for i in input().split()]
actions.sort(reverse=True)
secs = 0
poss = True
for act in actions:
    if act-actions[-1] % k != 0:
        poss = False
        break
    else:
        secs += act - actions[-1] // k
if poss:
    print(secs)
else:
    print(-1)
