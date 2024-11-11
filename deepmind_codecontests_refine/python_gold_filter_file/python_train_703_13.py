n, m = map(int, input().split())
sc = [tuple(map(int, input().split())) for _ in range(m)]

ans = '1'
if n == 1:
    ans = '0'
for i in range(n-1):
    ans += '0'

while len(ans) == n:
    if all([ans[s-1] == str(c) for s, c in sc]):
        print(ans)
        exit()
    ans = str(int(ans)+1)
print(-1)