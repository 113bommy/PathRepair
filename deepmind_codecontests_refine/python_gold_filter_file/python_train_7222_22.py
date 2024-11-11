import sys
a = [[1 if i == '#' else 0 for i in input()] for j in range(4)]
for i in range(3):
    for j in range(3):
        if a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] != 2:
            print("YES")
            sys.exit()
print("NO")

