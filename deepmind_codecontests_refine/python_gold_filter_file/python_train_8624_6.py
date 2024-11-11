N = int(input())
S = list(input())
ans = -1
for x in ['SS', 'SW', 'WS', 'WW']:
    for i, s in enumerate(S):
        if s=='o':
            if x[-1]=='S':
                x += x[-2]
            else:
                if x[-2]=='S':
                    x += 'W'
                else:
                    x += 'S'
        else:
            if x[-1] == 'S':
                if x[-2]=='S':
                    x += 'W'
                else:
                    x += 'S'
            else:
                x += x[-2]
    if x[0]==x[-2] and x[1]==x[-1]:
        ans = x[1:-1]
        break
print(ans)