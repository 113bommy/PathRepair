def solve():

    point123 = {(1, 1):None, (1, 2):"Bob", (1, 3):"Alice",
                (2, 1):"Alice", (2, 2):None, (2, 3):"Bob",
                (3, 1):"Bob", (3, 2):"Alice", (3, 3):None}
    map123 = {} # (a, b): (nexta, nextb)
    cycle123 = {} # (a, b): (cyclelen, Alicegain, Bobgain)

    k, a, b = [int(st) for st in input().split(" ")]
    A = [None, None, None, None]
    B = [None, None, None, None]

    for i in range(1, 4):
        A[i] = [None] + [int(st) for st in input().split(" ")]
    for i in range(1, 4):
        B[i] = [None] + [int(st) for st in input().split(" ")]

    for i in range(1, 4):
        for j in range(1, 4):
            map123[(i, j)] = (A[i][j], B[i][j])

    for i in range(1, 4):
        for j in range(1, 4):
            cycle = 1
            again, bgain = int(point123[(i, j)] == "Alice"), int(point123[(i, j)] == "Bob")
            i1, j1 = map123[(i, j)]
            while cycle < 10 and not (i1 == i and j1 == j):
                cycle += 1
                again += int(point123[(i1, j1)] == "Alice")
                bgain += int(point123[(i1, j1)] == "Bob")
                i1, j1 = map123[(i1, j1)]
                
            if cycle < 10:
                cycle123[(i, j)] = (cycle, again, bgain)

    print("Map", map123, "\nCycle", cycle123)

    ansA, ansB = 0, 0
    while k>0:
        
        if (a, b) in cycle123:
            if k % cycle123[(a, b)][0] == 0:
                ansA += cycle123[(a, b)][1] * k//cycle123[(a, b)][0]
                ansB += cycle123[(a, b)][2] * k//cycle123[(a, b)][0]
                return ansA, ansB
        
        k -= 1
        ansA += int(point123[(a, b)] == "Alice")
        ansB += int(point123[(a, b)] == "Bob")
        a, b = map123[(a, b)]

    return ansA, ansB

ansa, ansb = solve()
print(ansa, ansb)
