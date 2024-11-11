t = int(input())


def solve():
    cnt = int(input())
    animals = [int(x) for x in input().split()]
    prev = animals[0]
    currcnt = 1
    can_be_even = animals[0] == animals[-1] or cnt % 2 == 0
    #print(can_be_even)
    for i in range(1, cnt):
        if animals[i] == prev:
            can_be_even = True
        prev = animals[i]
    
    if all([x == animals[0] for x in animals]):
        # all the same
        print(1)
        print(*["1" for i in range(cnt)])
    elif cnt % 2 == 0 or animals[0] == animals[-1]:
        # alternate
        print(2)
        res = []
        curr_col = 0
        prev = -1
        comp = False
        for i in range(cnt):
            res.append(curr_col+1)
            curr_col = (curr_col + 1) % 2
        print(" ".join(map(str, res)))
    elif can_be_even:
        # alternate
        #print("can_be_even")
        print(2)
        res = []
        curr_col = 0
        prev_col = 0
        prev = -1
        comp = False
        for i in range(cnt):
            if not comp and animals[i] == prev:
                print("here")
                res.append(res[-1])
                comp = True
            else:
                res.append(curr_col+1)
                curr_col = (curr_col + 1) % 2
            prev = animals[i]
        print(" ".join(map(str, res)))
    else:
        # alternate until final one
        print(3)
        res = [3]
        curr_col = 0
        for i in range(cnt-1):
            res.append(curr_col+1)
            curr_col = (curr_col + 1) % 2
        print(" ".join(map(str, res)))

for i in range(t):
    solve()