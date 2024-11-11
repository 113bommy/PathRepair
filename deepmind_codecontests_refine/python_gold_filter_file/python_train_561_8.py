n, m, k = [int(i) for i in input().split()]

maze = []
for row in range (n):
    ro = []
    temp = input()
    for i in temp:
        if i == '.':
            ro.append(1)

        else:
            ro.append(0)
    maze.append(ro)
# print(maze)
done = 0
for i in range (n):
    if done == 1:
        break
    for j in range (m):
        if maze[i][j] == 1:
            root_node = [i, j]
            done = 1
            break

visited = [[0 for i in range (m)] for j in range (n)]

visited[root_node[0]][root_node[1]] = 1

levels = []
levels.append([root_node])
# print(root_node)

stop = 0
while True:
    if stop == 1:
        break

    else:
        bottom_most_nodes = levels[-1]
        upcoming_nodes = []
        
        for node in bottom_most_nodes:
            i, j = node[0], node[1]
            if i == 0:
                if j == 0:
                    for row, col in [[min(i+1, n-1), j], [i, min(j+1, m-1)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                elif j == m-1:
                    for row, col in [[min(i+1, n-1), j], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                else:
                    for row, col in [[min(i+1, n-1), j], [i, min(j+1, m-1)], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

            elif i == n-1:
                if j == 0:
                    for row, col in [[max(i-1, 0), j], [i, min(j+1, m-1)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                elif j == m-1:
                    for row, col in [[max(i-1, 0), j], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                else:
                    for row, col in [[max(i-1, 0), j], [i, min(j+1, m-1)], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

            else:
                if j == 0:
                    for row, col in [[max(i-1, 0), j], [min(i+1, n-1), j], [i, min(j+1, m-1)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                elif j == m-1:
                    for row, col in [[min(i+1, n-1), j], [max(i-1, 0), j], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

                else:
                    for row, col in [[min(i+1, n-1), j], [i, min(j+1, m-1)], [max(i-1, 0), j], [i, max(j-1, 0)]]:
                        if maze[row][col] == 1 and visited[row][col] == 0:
                            upcoming_nodes.append([row, col])
                            visited[row][col] = 1

        if upcoming_nodes == []:
            stop = 1
            break

        else:
            levels.append(upcoming_nodes)


final_arcitect = []
for i in maze:
    temp = []
    for j in i:
        temp.append(j)
    
    final_arcitect.append(temp)

remaining = k
while (remaining > 0):
    current_level = levels.pop(-1)
    if len(current_level) <= remaining:
        for j in current_level:
            maze[j[0]][j[1]] = -1
        
        remaining -= len(current_level)
    else:
        for j in range (remaining):
            maze[current_level[j][0]][current_level[j][1]] = -1

        remaining = 0

for i in range (n):
    line = ''
    for j in range (m):
        if maze[i][j] == 1:
            line += '.'
        elif maze[i][j] == 0:
            line += '#'
        else:
            line += 'X'
    print(line)
# for lev in levels:
#     print(lev)