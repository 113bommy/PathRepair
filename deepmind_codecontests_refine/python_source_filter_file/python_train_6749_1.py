


N = int(input())

r = []
for _ in range(N):
    x,y = map(int, input().split())
    r.append((-y,x))

b = []
for _ in range(N):
    x,y = map(int, input().split())
    b.append((y,x))

r.sort()
b.sort()

ans = 0
for my,x in r:
    for j in range(len(b)):
        if  -my < b[j][0] and x < b[j][1]:
            ans += 1
            b.pop(j)
            break

print(ans)
