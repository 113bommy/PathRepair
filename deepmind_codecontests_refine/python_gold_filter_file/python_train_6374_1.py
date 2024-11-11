from sys import stdin, gettrace

from collections import deque

# if not gettrace():
#     def input():
#         return next(stdin)[:-1]
#

def input():
   return stdin.buffer.readline()

def main():
    n = int(input())
    grid = [[None]*(n+2) for _ in range(n+2)]
    res = [['']*(n+2) for _ in range(n+2)]
    for i in range(1, n+1):
        line = (int(a) for a in input().split())
        for j in range(1,n+1):
            x = next(line)
            y = next(line)
            if i == x and j == y:
                res[i][j] = 'X'
                grid[i][j] = (-2, -2)
            else:
                grid[i][j] = (x, y)
    filled = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            if res[i][j] == 'X':
                filled += 1
                q = deque()
                q.append((i,j))
                while q:
                    x, y = q.pop()
                    if grid[x-1][y] == (i,j):
                        res[x-1][y] = 'D'
                        q.append((x-1, y))
                        grid[x - 1][y] = (-2,-2)
                        filled += 1
                    if grid[x+1][y] == (i,j):
                        res[x+1][y] = 'U'
                        q.append((x+1, y))
                        grid[x + 1][y] = (-2, -2)
                        filled += 1
                    if grid[x][y-1] == (i,j):
                        res[x][y-1] = 'R'
                        q.append((x, y-1))
                        grid[x][y-1] = (-2, -2)
                        filled += 1
                    if grid[x][y+1] == (i,j):
                        res[x][y+1] = 'L'
                        q.append((x, y+1))
                        grid[x][y+1] = (-2, -2)
                        filled += 1
            if grid[i][j] == (-1, -1):
                filled += 1
                if grid[i-1][j] == (-1, -1):
                    res[i][j] = 'U'
                elif grid[i+1][j] == (-1, -1):
                    res[i][j] = 'D'
                elif grid[i][j-1] == (-1, -1):
                    res[i][j] = 'L'
                elif grid[i][j+1] == (-1, -1):
                    res[i][j] = 'R'
                else:
                    print("INVALID")
                    return
    if filled != n*n:
        print("INVALID")
        return
    print("VALID")
    for i in range(1,n+1):
        print(''.join(res[i][1:n+1]))


if __name__ == "__main__":
    main()