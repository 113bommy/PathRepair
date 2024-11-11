# import sys
# 
# f = open('input1.txt', 'r')
# 
# 
# sys.stdin = f

n, m, p = list(map(int, input().split()))
s = list(map(int, input().split()))

q = [[] for _ in range(p)] # fromnt of each palyer
counts = [0] * p

field = []
for i in range(n):
    line = input()
    field.append([0] * m)
    for j, c in enumerate(line):
        if c == '.':
            field[i][j] = 0
        elif c == '#':
            field[i][j] = -1
        else:
            # player
            pi = int(c)
            field[i][j] = pi
            counts[pi-1] += 1

def get_neibs(i, j):
    up = (i - 1, j) if i > 0 else None
    down = (i + 1, j) if i < n - 1 else None
    left = (i, j - 1) if j > 0 else None
    right = (i, j + 1) if j < n - 1 else None
    nbs = [up, down, left, right]
    return [a for a in nbs if a is not None]



def init_bounds(field, q):
    for i in range(n):
        for j in range(m):
            if field[i][j] > 0:
                index  = field[i][j]-1
                nbs = get_neibs(i, j)
                neib_vals = [field[a[0]][a[1]] for a in nbs]
                if 0 in neib_vals:
                    q[index].append((i, j))

def step_one(index, field, front: list):
    new_front = []

    total_add = 0
    for i, j in front:
        nbs = get_neibs(i, j)
        for a in nbs:
            if field[a[0]][a[1]] == 0:
                # if not yet added
                field[a[0]][a[1]] = index+1
                counts[index] += 1
                total_add += 1
                new_front.append(a)


    return new_front, total_add





def  step(index, field, front, speed):
    added_len = 0
    while speed > 0:
        front, added_len = step_one(index, field, front)
        speed -= 1
        if added_len == 0:
            break

    q[index] = front
    return front, added_len

init_bounds(field, q)

while True:

    progress = 0
    added = 0
    for i in range(p):
        _, added = step(i, field, q[i], s[i])
        progress += added

    if progress == 0:
        break



print(" ".join(map(str, counts)))

# f.close()
