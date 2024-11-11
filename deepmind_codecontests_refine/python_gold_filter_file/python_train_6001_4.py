n, m = list(map(int, input().split()))
matrix = [input() for i in range(n)]
program = input()
num_of_right = 0

for u in range(4):
    for d in range(4):
        if d == u:
            continue
        for l in range(4):
            if l == d or l == u:
                continue
            for r in range(4):
                if r == l or r == u or r == d:
                    continue
                
                directions = {str(u): [1, 0], str(d): [-1, 0],
                              str(r): [0, 1], str(l): [0, -1]}
                coords = [0, 0]
                for i in range(n):
                    if 'S' in matrix[i]:
                        coords = [i, matrix[i].index('S')]
                        break
                result = 0
                #print(directions)
                for command in program:
                    coords = [coords[0] + directions[command][0],
                              coords[1] + directions[command][1]]
                    #print(coords)
                    if (coords[0] < 0 or coords[0] >= n or \
                        coords[1] < 0 or coords[1] >= m):
                        break
                    current = matrix[coords[0]][coords[1]]
                    if current == '#':
                        break
                    if current == 'E':
                        result = 1
                        break

                if result:
                    num_of_right += 1
                #print()
print(num_of_right)
