t = int(input())
for el in range(t):
    x, y = map(int, input().split())
    if x - y > 1:
        print("YES")
    else:
        print("NO")