def optimize(path): # LLR
    time = 0
    visits = {
        (0,0): 0
    }
    position = (0,0)
    current_min = float('inf')
    best_subpath = (-1, -1)

    for direction in path: # L
        position = move(direction, position) # (-1, 0)
        time += 1 # 1
        if position not in visits: # True
            visits[position] = time # {(0, 0): 0, (-1, 0): 1}
            continue

        subpath_length = time - visits[position]
        if subpath_length  < current_min:
            current_min = subpath_length
            best_subpath = (visits[position], time)
        
        visits[position] = time
        
    best_left, best_right = best_subpath
    return best_left + 1, best_right

def move(direction, position):
    x, y = position
    possible_moves = {
        'L': (x-1, y),
        'R': (x+1, y),
        'U': (x, y+1),
        'D': (x, y-1)
    }

    return possible_moves[direction]


number_of_tests = int(input())
for _ in range(number_of_tests):
    input()
    path = input()
    left, right = optimize(path)
    if right == -1:
        print(-1)
        continue

    print(left, right)
