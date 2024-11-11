import sys
max_int = 1000000001  # 10^9+1
min_int = -max_int

t = int(input())
for _t in range(t):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    if len(a) == 1:
        print(0)
        continue
    cur_level = [0, 1]
    next_level = [0, 0]
    level = 1
    for aa in a[1:]:
        print(cur_level, next_level, aa)
        while cur_level[1]:
            if aa > cur_level[0]:
                cur_level[0] = aa
                next_level[1] += 1
                break
            else:
                cur_level[1] -= 1
                cur_level[0] = 0
        else:
            level += 1
            cur_level = [aa, next_level[1]]
            next_level = [0, 1]

        print(cur_level, next_level)

    print(level)



