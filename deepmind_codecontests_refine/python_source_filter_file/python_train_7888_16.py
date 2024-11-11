n = int(input())
xl = sorted([list(map(int, input().split())) for _ in range(n)], key = lambda x: x[0]+x[1])

x, l = xl[0]
ans = n
for i in range(1, n):
    if x+l-1 < xl[i][0]-xl[i][1]+1:
        x, l = xl[i]
    else:
        ans -= 1

print(ans)