from collections import deque
N = 3
m = {8: {7, 5}, 7: {8, 6, 4}, 6: {7, 3}, 5: {8, 4, 2}, 4: {7, 5, 3, 1}, 3: {6, 4, 0}, 2: {5, 1}, 1: {4, 2, 0},
     0: {3, 1}}
goal = 123456780
def g(i, j, a):
    t = a // (10 ** j) % 10
    return a - t * (10 ** j) + t * (10 ** i)
def solve():
    MAP = "".join(input().replace(" ", "") for _ in range(N))
    zero = 8 - MAP.find("0")
    start = int(MAP)
    if MAP == goal:
        return 0
    dp = deque([(0, start, zero, 1), (0, goal, 0, 0)])
    TABLE = {start: (1, 0), goal: (0, 0)}
    while dp:
        cnt, M, yx, flg = dp.popleft()
        cnt += 1
        for nyx in m[yx]:
            key = g(yx, nyx, M)
            if key in TABLE:
                if TABLE[key][0] != flg:
                    return TABLE[key][1] + cnt
                continue
            TABLE[key] = (flg, cnt)
            dp.append((cnt, key, nyx, flg))
def MAIN():
    print(solve())
MAIN()

