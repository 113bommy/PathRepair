n,m,d = map(int, input().split())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
b = []
for i in a:
    b += i
b.sort()
z= b[n//2]
flag = 0
ans = 0
for i in range(n*m):
    if abs(z-b[i])%d!=0:
        flag = 1
        break
    else:
        ans += abs(z-b[i])//d
if flag==1:
    print(-1)
else:
    print(ans)
