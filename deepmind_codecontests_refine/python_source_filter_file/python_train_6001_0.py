from itertools import permutations

n = 0
m = 0
grid = []
path = ''
ct = 0
direc = []
bas = [0, 1, 2, 3]
s_x = 0
s_y = 0
e_x = 0
e_y = 0
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def io():
    global n, m, grid, path
    n, m = map(int, input().split(' '))
    for i in range(0, n, 1):
        grid.append(input())
    path = input()


def preprocess():
    global s_x, s_y, e_x, e_y
    for i in range(0, n, 1):
        for j in range(0, m, 1):
            if grid[i][j] == 'S':
                s_x = i
                s_y = j
            elif grid[i][j] == 'E':
                e_x = i
                e_y = j


def reached():
    curr_x = s_x
    curr_y = s_y
    for d in path:
        ind = direc[int(d) - 0]
        curr_x += dx[ind]
        curr_y += dy[ind]
        if curr_x < 0 or curr_x >= n or curr_y < 0 or curr_y >= m:
            return False
        elif grid[curr_x][curr_y] == 'H':
            return False
        elif grid[curr_x][curr_y] == 'E':
            return True
    return False


def main():
    global ct, direc, bas
    io()
    #print(path)
    preprocess()
    #pt = 0
    for subset in permutations(bas, 4):
        direc = subset
        #pt += 1
        #print(subset)
        if reached():
            ct += 1
    print(str(ct))

main()