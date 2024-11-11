s = [list(input()) for i in range(4)]
for i in range(3):
    for j in range(3):
        square = s[i][j] + s[i+1][j] + s[i][j+1] + s[i+1][j+1]
        if square.count('#') == 3 or square.count(".") == 3:
            print("YES")
            exit(0)
print("NO")