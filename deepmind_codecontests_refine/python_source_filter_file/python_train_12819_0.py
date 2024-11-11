
def reach(x,y, matrix):
    res = set()
    res.add((x,y))
    frontier = set()
    isFirst = True
    if x - 1 >= 0 and matrix[x-1][y] == 0:
        frontier.add((x-1,y))
        res.add((x-1,y))
    if x + 1 < len(matrix) and matrix[x+1][y] == 0:
        frontier.add((x+1,y))
        res.add((x+1,y))
    if y - 1 >= 0 and matrix[x][y-1] == 0:
        frontier.add((x,y-1))
        res.add((x,y-1))
    if y + 1 < len(matrix) and matrix[x][y+1] == 0:
        frontier.add((x,y+1))
        res.add((x,y+1))
    while len(frontier) > 0:
        toConsider = frontier.pop()
        x = toConsider[0]
        y = toConsider[1]
        if x - 1 >= 0 and matrix[x-1][y] == 0 and (x-1,y) not in res:
            frontier.add((x-1,y))
            res.add((x-1,y))
        if x + 1 < len(matrix) and matrix[x+1][y] == 0 and (x+1,y) not in res:

            frontier.add((x+1,y))
            res.add((x+1,y))
        if y - 1 >= 0 and matrix[x][y-1] == 0 and (x,y-1) not in res:
            frontier.add((x,y-1))
            res.add((x,y-1))
        if y + 1 < len(matrix) and matrix[x][y+1] == 0 and (x,y+1) not in res:
            frontier.add((x,y+1))
            res.add((x,y+1))
    return res

def cost(t1, t2):
    return (t1[0] - t2[0])**2 + (t1[1] - t2[1])**2


if __name__ == "__main__":
    size = int(input())
    start = input().split(' ')
    end = input().split(' ')
    matrix = []
    for i in range(0, size):
        toInsert = []
        data = input()
        for c in data:
            toInsert.append(int(c))
        matrix.append(toInsert)
    fromStart =  reach(int(start[0]) - 1,int(start[1]) - 1, matrix)
    fromEnd = reach(int(end[0]) - 1,int(end[1]) - 1, matrix)
    res = -1
    calculated = set()
    if len(fromStart.intersection(fromEnd)) > 0:
        print(0)
    else:
        for s in fromStart:
            for e in fromEnd:
                if (s,e) not in calculated:
                    c = cost(s,e)
                    calculated.add((s,e))
                    calculated.add(((s[1],s[0]),(e[1],e[0])))
                    if res == -1 or c < res:
                        res = c
    print(res)
