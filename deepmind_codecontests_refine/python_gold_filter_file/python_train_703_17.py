N,M=map(int, input().split())

sc = []
for i in range(M):
    sc.append(list(map(int, input().split())))
for i in range(10**N):
    ans = str(i)
    if len(ans) == N and all(ans[s-1] == str(c) for s,c in sc):
        print(ans)
        quit()
print(-1)
