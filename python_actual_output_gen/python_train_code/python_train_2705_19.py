N = int(input())
XL = []
for i in range(N):
    x,l = map(int,input().split())
    XL.append((x-l+1,x+l-1))

XL.sort(key=lambda x: (x[1]))

ans = 0
t = -10**9
for i in range(N):
    if t <= XL[i][0]:
        ans += 1
        t = XL[i][1]
print(ans)