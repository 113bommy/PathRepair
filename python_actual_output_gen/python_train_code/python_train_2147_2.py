n,m = map(int,input().split())
li = [list(map(int,input().split()))for i in range(n)]

li.sort()
n = 0
ans = 0
for i in range(n):
    a = min(m,li[i][1])
    m-=a
    ans += li[i][0]*a
    if a ==0:
        break
print(ans)
