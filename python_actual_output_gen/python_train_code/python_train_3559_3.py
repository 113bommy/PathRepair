b, g = map(int, input().split())
print(g + b - 1)
for i in range(1, b+1):
    for j in range(1, g+1):
        print(i, j)
        if (i >= 1):
            break