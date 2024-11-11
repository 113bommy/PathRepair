# 8 Puzzle
import copy
z = 0
[N, d] = [3, 0]
check_flag = [[1, 2, 3, 4,  1, 2, 3, 4,  1, 2, 3, 4],
              [2, 3, 4, 1,  2, 3, 4, 1,  2, 3, 4, 1],
              [3, 4, 1, 2,  3, 4, 1, 2,  3, 4, 1, 2],
              [4, 1, 2, 3,  4, 1, 2, 3,  4, 1, 2, 3],
              [3, 2, 1, 4,  3, 2, 1, 4,  3, 2, 1, 4],
              [2, 1, 4, 3,  2, 1, 4, 3,  2, 1, 4, 3],
              [1, 4, 3, 2,  1, 4, 3, 2,  1, 4, 3, 2],
              [4, 3, 2, 1,  4, 3, 2, 1,  4, 3, 2, 1]]

start = []
goal = [[i + j*N for i in range(1, N + 1)] for j in range(N)]
goal[2][2] = 0
for i in range(N):
    start.append(list(map(int, input().split())))


def manhattan(value, pairs):
    h = 0

    if value == 1:
        h = (pairs[0] + pairs[1])
    if value == 2:
        h = (pairs[0] + abs(pairs[1] - 1))
    if value == 3:
        h = (pairs[0] + abs(pairs[1] - 2))
    
    if value == 4:
        h = (abs(pairs[0] - 1) + pairs[1])
    if value == 5:
        h = (abs(pairs[0] - 1) + abs(pairs[1] - 1)) 
    if value == 6:
        h = (abs(pairs[0] - 1) + abs(pairs[1] - 2))
        
    if value == 7:
        h = (abs(pairs[0] - 2) + pairs[1])      
    if value == 8:
        h = (abs(pairs[0] - 2) + abs(pairs[1] - 1))
        
    return h

def flag_array(flag, input):

    flag.pop(0)
    flag.append(input)
    return flag


s_h = 0
for i in range(N):
    for j in range(N):
        s_h += manhattan(start[i][j], [i, j])

# print(s_h)

for i in range(N):
        check = start[i].count(0)
        if check != 0:
            [s_r, s_c] = [i, start[i].index(0)]
            break
        if i == 3:
            print("Error")

while True:
    d += 1
    queue = []
    flag = [0 for i in range(12)]
    queue.append([s_h, start, 0, [s_r, s_c], flag])

    #while True:
    while len(queue) != 0:
        #print("Q: ", len(queue), "depth: ", d)
        short_n = queue.pop(0)
        h = short_n[0] - short_n[2]
        state = short_n[1]
        g = short_n[2]
        [r, c] = short_n[3]
        flag = short_n[4]
        print("left_Q: ", len(queue), "depth: ", d, "h: ", h, "g: ", g, "state: ", state, "g+h: ", short_n[0], "flag: ", flag[len(flag) - 1])
        #print("left_Q: ", len(queue), "depth: ", d, "h: ", h, "g: ", g, "flag: ", flag, "g+h: ", short_n[0])
        #if d == 1:
            #print(short_n[0])
            #print(state)
            #print(g)

        if h == 0:
            print(short_n[2])
            print(z)
            break
        """
        if flag in check_flag:
            z += 1
            continue
        """
        if r - 1 >= 0 and flag[len(flag) - 1] != 3:
            [temp, temp_array] = [copy.deepcopy(state), flag[:]]
            h = short_n[0] - short_n[2] - manhattan(temp[r - 1][c], [r - 1, c]) + manhattan(temp[r - 1][c], [r, c])
            [temp[r][c], temp[r - 1][c]] = [temp[r - 1][c], temp[r][c]]
            #if temp[r][c] != goal[r][c]:
            #[r, c] = [r - 1, c]
            #if temp
            #h = manhattan(temp)
            #print("1: ", h, temp)
            if g + 1 + h <= d:
                queue.append([h + g + 1, temp, g + 1, [r - 1, c], flag_array(temp_array, 1)])
        
        if c + 1 < N and flag[len(flag) - 1] != 4:
            #print("2: ")
            [temp, temp_array] = [copy.deepcopy(state), flag[:]]
            #temp_array = copy.deepcopy(flag)
            h = short_n[0] - short_n[2] - manhattan(temp[r][c + 1], [r, c + 1]) + manhattan(temp[r][c + 1], [r, c])
            [temp[r][c], temp[r][c + 1]] = [temp[r][c + 1], temp[r][c]]
            #queue.append(calculate(temp, g + 1))
            #print("2: ", h, temp)
            if g + 1 + h <= d:
                queue.append([h + g + 1, temp, g + 1, [r, c + 1], flag_array(temp_array, 2)])

        if r + 1 < N and flag[len(flag) - 1] != 1:
            #print("3: ")
            [temp, temp_array] = [copy.deepcopy(state), flag[:]]
            #temp_array = copy.deepcopy(flag)
            h = short_n[0] - short_n[2] - manhattan(temp[r + 1][c], [r + 1, c]) + manhattan(temp[r + 1][c], [r, c])
            [temp[r][c], temp[r + 1][c]] = [temp[r + 1][c], temp[r][c]]
            #queue.append(calculate(temp, g + 1))
            #print("3: ", h, temp)
            if g + 1 + h <= d:
                queue.append([h + g + 1, temp, g + 1, [r + 1, c], flag_array(temp_array, 3)])
        
        if c - 1 >= 0 and flag[len(flag) - 1] != 2:
            #print("4: ")
            [temp, temp_array] = [copy.deepcopy(state), flag[:]]
            h = short_n[0] - short_n[2] - manhattan(temp[r][c - 1], [r, c - 1]) + manhattan(temp[r][c - 1], [r, c])
            [temp[r][c], temp[r][c - 1]] = [temp[r][c - 1], temp[r][c]]
            if g + 1 + h <= d:
                queue.append([h + g + 1, temp, g + 1, [r, c - 1], flag_array(temp_array, 4)])
                
        queue.sort(key = lambda data:data[0])
        queue.sort(key = lambda data:data[2], reverse = True)

        data = []
        g_data = []
        #print(queue)
        """
        for i in range(len(queue)):
            data.append(str(queue[i][0]))
            g_data.append(str(queue[i][2]))
            #print(queue[i])
        print("g+h: ",' '.join(data))
        print("g: ",' '.join(g_data))
        """
        #if d == 1:
        #print(len(queue))

    if state == goal:
        break
