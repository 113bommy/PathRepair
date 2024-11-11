N, M = map(int, input().split())
x = [list(map(int, input().split())) for _ in range(N)]
y = [list(map(int, input().split())) for _ in range(M)]
for a,b in x:
    z = [abs(a-c) + abs(b-d) for c,d in y]
    print(z.index(min(z))+1)