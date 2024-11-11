t = int(input())
for i in range(t):
    n,m = map(int, input().split())
    for j in range(n):
        for k in range(m):
            if j == 0 and k == 0:
                print("W", end="")
            else:
                print("B", end="")
        print()