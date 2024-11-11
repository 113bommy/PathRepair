import sys
input = sys.stdin.readline

Q = int(input())
Query = []
for _ in range(Q):
    N = int(input())
    S = input().rstrip()
    Query.append((N, S))


for N, S in Query:
    ang = False
    c = 0
    ans = 0
    for i in range(N):
        if S[i] == "A":
            ang = True
            c = 0
        elif ang:
            c += 1
            ans = max(ans, c)
    print(c)