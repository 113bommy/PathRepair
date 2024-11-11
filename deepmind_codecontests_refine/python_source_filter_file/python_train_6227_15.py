n,m = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(n)]
ab.sort()
ans = 0
cnt = 0
i = 0
while cnt < m:
    ans += ab[i][0]*ab[i][1]
    cnt += ab[i][1]
    i += 1
print(num - (cnt - m)*ab[i][0])