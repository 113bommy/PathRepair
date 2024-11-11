N = int(input())
for _ in range(N):
    t, x, y = map(int, input().split())
    if x + y > t or (t + x + y)%2 != 0:
        print("No")
        break
print("Yes")