import sys
input = sys.stdin.readline

N,A,B = map(int,input().split())

def seq(start,bits):
    arr = [0]
    for i in bits:
        arr += [x^(1<<i) for x in arr[::-1]]
    return [x^start for x in arr]

def solve(A,B,rest):
    if len(rest) == 1:
        return [A,B]
    if len(rest) == 2:
        i,j = rest
        x,y = 1<<i,1<<j
        if A^x == B:
            return [A,A^y,A^x^y,B]
        elif A^y == B:
            return [A,A^x,A^x^y,B]
        else:
            return None
    diff_bit = [i for i in rest if (A&(1<<i)) != (B&(1<<i))]
    if len(diff_bit) % 2 == 0:
        return None
    i = diff_bit[0]
    rest = [j for j in rest if j != i]
    if A^(1<<rest[0])^(1<<i) == B:
        rest[0],rest[1] = rest[1],rest[0]
    arr = seq(A,rest)
    return arr + seq(arr[-1]^(1<<i),rest)

rest = list(range(N))
answer = solve(A,B,rest)

if answer is None:
    print('NO')
else:
    print('YES')
    print(' '.join(map(str,answer)))