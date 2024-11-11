x, y = map(int, input().split())

ans = []

for i in range(x):
    for j in range(x):
        if y > 0 and (i + j) % 2 == 0:
            ans.append("L")
            y -= 1
        else:
            ans.append("S")
    ans.append("\n")

if y > 0:
    print("NO")
else:
    print("YES")
    print("".join(ans), end="")