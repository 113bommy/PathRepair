import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N,Q = map(int,input().split())
AB = [[int(x) for x in input().split()] for _ in range(Q)]

cup = list(range(N+1)) + [0]
se = set([0,1,2])
for a,b in AB:
    cup[a],cup[b] = cup[b],cup[a]
    for x in [a,b]:
        if cup[x] == 1:
            ball = x
    se.add(cup[ball-1])
    se.add(cup[ball+1])

se.remove(0)
answer = len(se)
print(answer)

