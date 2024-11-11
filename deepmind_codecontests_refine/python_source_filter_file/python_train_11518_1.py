moves = [
    [(1,24),(3,22),(5,1),(7,3),(9,5),(11,7),(24,9),(22,11),(14,13),(13,15),(15,16),(16,13)],
    [(14,4),(16,3),(9,14),(10,16),(19,9),(17,10),(3,17),(4,19),(5,6),(6,8),(8,7),(7,5)],
    [(5,13),(6,14),(17,5),(18,6),(12,17),(11,18),(14,11),(13,12),(1,2),(2,4),(4,3),(3,1)]
]

moves_len = len(moves)
for i in range(moves_len):
    moves.append([])
    for t in range(len(moves[i])):
        moves[-1].append((moves[i][t][1], moves[i][t][0]))


colors = input().split()

def is_solved(col):
    for s in range(6):
        for i in range(s * 4 + 1, s * 4 + 4):
            if col[i] != col[s * 4]:
                return False

    return True

def check_move(col, move):
    col_temp = colors[:]
    for t in move:
        col_temp[t[1]-1] = colors[t[0]-1]
    return is_solved(col_temp)

solved = False
for m in moves:
    solved = check_move(colors, m)
    if solved:
        break

print("YES" if solved else "NO")