import sys
f = sys.stdin


board = [[0 for i in range(11)] for j in range(11)]
for i, line in enumerate(f):
    for j, c in enumerate(line.strip()):
        board[i + 1][1 + (i + 1) % 2 + j * 2] = int(c)

step = {(-1, 0 ):'L',(0, -1 ):'U',(1, 0 ):'R',(0, 1):'D'}
    
    
start = pre_loc = 1 + 1j
loc = 3 + 1j
print('R',end='')
while loc != start:
    for direct in [(pre_loc - loc) / 2 * 1j ** (i + 1) for i in range(3)]:
        if board[int(loc.imag + direct.imag)][int(loc.real + direct.real)]:
            pre_loc = loc
            loc += direct * 2
            print(step[(direct.real,direct.imag)],end='')
            break
print()