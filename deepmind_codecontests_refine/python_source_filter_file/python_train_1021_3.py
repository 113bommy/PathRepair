h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]
r = "Yes"
for i in range(1, h-1):
    for j in range(1, w-1):
        if a[i][j] == "#" and a[i - 1][j] == "." and a[i + 1][j] == "." and a[i][j - 1] == "." and a[i][j + 1] == ".":
          r = "No"
print(r)
