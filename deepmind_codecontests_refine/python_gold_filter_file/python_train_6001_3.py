from collections import namedtuple
import itertools
n, m = map(int, input().split())
Point = namedtuple('Point', 'i j')
start = None
end = None


isObs = [[False for x in range(m)] for y in range(n)]
for i in range(n):
    line = input()
    for j in range(m):
        if line[j] == '#':
            isObs[i][j] = True
        if line[j] == "S":
            start = Point(i, j)
        if line[j] == "E":
            end = Point(i, j)

instructions = input()
nums = ['0','1','2','3']
dirs = itertools.permutations(['u','l', 'r', 'd'])
ways = 0
for perm in dirs:
    dirDict = dict(zip(nums, perm))
    i, j = start[0], start[1]
    for ins in instructions:
        mov = dirDict[ins]
        if mov == 'u':
            i -= 1
        if mov == 'd':
            i += 1
        if mov == 'l':
            j -= 1
        if mov == 'r':
            j += 1
        if i < 0 or j < 0 or i >= n or j >= m or isObs[i][j]:
            break
        if i == end[0] and j == end[1]:
            ways += 1
            break
print(ways)
