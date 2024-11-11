N, M = map(int, input().split())
sc = [list(map(int, input().split())) for i in range(M)]
for i in range(0, 10**N):
    if len(str(i))==N and all(str(i)[s-1] == c for s,c in sc):
        print(i)
        break
else:
    print(-1)