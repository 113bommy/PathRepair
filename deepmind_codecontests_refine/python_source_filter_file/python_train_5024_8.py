from collections import defaultdict

for _ in range(int(input())):
    n = int(input())
    ls = list(map(int, input().split()))
    mem = defaultdict(int)
    for i in ls:
        temp = i
        cc = 0
        while temp:
            if temp % 2:
                mem[cc] += 1
            temp //= 2
            cc += 1
    flag = 0
    for i in sorted(mem.keys(), reverse=True):
        if mem[i] % 2 == 0:
            continue
        elif mem[i] % 4 == 3:
            print("LOSE")
            flag = 1
            break
        else:
            flag = 1
            print("WIN")
            break
    if flag == 0:
        print("DRAW")
