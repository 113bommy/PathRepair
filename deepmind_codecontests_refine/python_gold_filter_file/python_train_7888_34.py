N = int(input())
XL = [tuple(map(int,input().split())) for i in range(N)]
XL.sort(key=lambda x: x[0]+x[1])
right = -float('inf')
ans = 0
for x,l in XL:
    s,t = x-l, x+l-1
    if s > right:
        right = t
        ans += 1
print(ans)