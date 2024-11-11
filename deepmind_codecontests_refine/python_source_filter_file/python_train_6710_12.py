def solve(a) -> int:
    cur = 0
    ret = 0
    for x in a:
        ret += 1
        cur += x
        if cur < 2:
            break
        cur //= 2
    return ret

input()
print(solve(list(map(int,input()))))