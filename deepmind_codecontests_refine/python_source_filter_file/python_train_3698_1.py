def solve():
    n = int(input())
    s = input()
    cards = {'R': 0, 'G': 0, 'B': 0}
    for c in s:
        cards[c] += 1
    if cards['R'] > 0 and cards['G'] > 0 and cards['B'] > 0:
        return 'BGR'
    if cards['R'] == 0 and cards['G'] == 0 or \
       cards['R'] == 0 and cards['B'] == 0 or \
       cards['G'] == 0 and cards['B'] == 0:
        if cards['R'] > 0:
            return 'R'
        if cards['G'] > 0:
            return 'G'
        return 'B'
    if cards['R'] == 0:
        if cards['G'] == cards['B'] == 1:
            return 'R'
        if cards['G'] > 1 and cards['B'] > 1:
            return 'BGR'
        if cards['G'] > cards['B']:
            return 'BR'
        return 'BG'
    if cards['G'] == 0:
        if cards['R'] == cards['B'] == 1:
            return 'G'
        if cards['R'] > 1 and cards['B'] > 1:
            return 'BGR'
        if cards['R'] > cards['B']:
            return 'BG'
        return 'GR'
    if cards['B'] == 0:
        if cards['R'] == cards['G'] == 1:
            return 'B'
        if cards['G'] > 1 and cards['R'] > 1:
            return 'BGR'
        if cards['R'] > cards['G']:
            return 'BG'
        return 'BR'


print(solve())
