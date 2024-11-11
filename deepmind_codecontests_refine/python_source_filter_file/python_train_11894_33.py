s = [[2, 4, 1, 3], [1, 4, 2, 5, 3], [2, 6, 3, 5, 1, 4], [1,5, 2, 4, 5, 3, 6]]
import sys;input=sys.stdin.readline
T, = map(int, input().split())
for _ in range(T):
    N=int(input())
    if N<=3:
        print(-1)
    elif N<=7:
        print(*s[N-4])
    else:
        r = []
        for i in range(N//4 - 1):
            r += [x+4*i for x in s[0]]
        r += [x+4*(N//4 - 1) for x in s[N%4]]
        print(*r)



