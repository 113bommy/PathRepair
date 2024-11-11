t = int(input())
for i in range(t):
    map = {'R':0, 'S':0, 'P':0}
    seq = str(input())
    n = len(seq)
    for s in seq:
        map[s] += 1
    if map['R']>map['S'] and map['R']>map['P']:
        maxs = 'P'
    elif map['S']>map['R'] and map['S']>map['P']:
        maxs = 'R'
    elif map['P']>map['R'] and map['P']>map['S']:
        maxs = 'S'
    print(''.join([maxs]*n))

