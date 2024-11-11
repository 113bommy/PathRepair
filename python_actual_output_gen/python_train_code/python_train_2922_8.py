n = int(input())
sdi = [list(map(int,input().split())) for i in range(n)]
ans = 0
for i in range(n):
    if ans <= sdi[i][0]:
        ans = sdi[i][0]
    else:
        ans += sdi[i][1]-((ans - sdi[i][0]) % sdi[i][1])
print(ans)
