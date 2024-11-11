num_barriers, finish, min_run, max_jump = tuple(map(int, input().split()))

barriers = list(map(int, input().split())) + [-1]
barriers.sort()

for i in range(len(barriers) - 1):
    if barriers[i + 1] - barriers[i] <= min_run:
        barriers[i] = (0, barriers[i] + 1, barriers[i + 1] - 1)  # nope
    else:
        barriers[i] = (1, barriers[i] + 1, barriers[i + 1] - 1)  # ok

barriers[len(barriers) - 1] = (1, barriers[len(barriers) - 1] + 1, finish)

if not barriers:
    pass
elif not barriers[0][0]:
    print('IMPOSSIBLE')
else:
    commands = []
    pos = 0

    for tpe, st, en in barriers:
        if tpe:
            if pos != st and st - pos <= max_jump:
                commands.append('JUMP %s' % (st - pos))
            elif pos != st:
                print('IMPOSSIBLE')
                break
            if en - st:
                commands.append('RUN %s' % (en - st))
            pos = en
    else:
        print('\n'.join(commands))
