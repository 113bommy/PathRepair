# your code goes here
def read_data():
    maps = [input() for n in range(8)]
    return maps

def decode(maps):
    step_b = 1000
    step_a = 1000
    for col in range(8):
        mina, maxa = find_range(maps, col, 'W')
        minb, maxb = find_range(maps, col, 'B')
        if mina < minb:
            step_a = min(step_a, mina)
        if maxb > maxa:
            step_b = min(step_b, 7 - maxb)
    if step_a <= step_b:
        return 'A'
    else:
        return 'B'

def find_range(maps, col, ch):
    minc = float('inf')
    maxc = - float('inf')
    for row in range(8):
        if maps[row][col] == ch:
            minc = min(minc, row)
            maxc = max(maxc, row)
    return minc, maxc


maps = read_data()
print(decode(maps))
