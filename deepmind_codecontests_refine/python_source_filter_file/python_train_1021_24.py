h, w = map(int, input().split())
s = [list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        if s[i][j] == "#" and s[i - 1][j] != "#" and s[i][j - 1] != "#" and s[i + 1][j] != "#" and s[i][j + 1] != "#":
            print("No")
            exit()
print("Yes")