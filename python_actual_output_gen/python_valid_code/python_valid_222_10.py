N = int(input())
AB = [tuple(map(int,input().split())) for i in range(N)]
AB.sort(key=lambda x:x[1]+x[0])

ans = 0
for i,(a,b) in enumerate(AB):
    if i%2:
        ans -= b
    else:
        ans += a
print(ans)