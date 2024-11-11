
rows = int(input())
queen_pos = [int(i) for i in input().split()]
king_pos = [int(i) for i in input().split()]
target_pos = [int(i) for i in input().split()]


def valid(king_pos):
    return 0 < king_pos[0] <= rows and 0 < king_pos[1] <= rows


def good(king_pos):
    return valid(king_pos) and not check(king_pos)


def next_position(pos):
    (i, j) = pos
    return [(i+1, j), (i, j+1), (i-1, j), (i, j-1), (i+1, j+1), (i-1, j-1),
            (i+1, j-1), (i-1, j+1)]


def check(king_pos):
    return queen_pos[0] == king_pos[0] or queen_pos[1] == king_pos[1] or queen_pos[0] - king_pos[0] == queen_pos[1] - king_pos[1]


def is_closer(first, second):
    return (first[0] - target_pos[0] + first[1] - target_pos[1]) >= (second[0]-target_pos[0] + second[1] - target_pos[1])


stack = [king_pos]
visited = set(tuple(king_pos))
found = False
while stack:
    pos = stack.pop()
    if pos == tuple(target_pos):
        found = True
        break
    for next_pos in next_position(pos):
        if good(next_pos) and next_pos not in visited:
            visited.add(next_pos)
            stack.append(next_pos)

if found:
    print("YES")
else:
    print("NO")
