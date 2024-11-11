N = int(input())
b = 0
for i in range(N):
    t, x, y = map(int, input().split())
    if t < (x+y) or (t+x+y) % 2:
        print("NO")
        b = 1
        break
if b == 0:
    print("YES")
