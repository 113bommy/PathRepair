n = int(input())
for i in range(n):
    u, k, *v = map(int, input().split())
    row = ""
    for j in range(1, n + 1):
        if j in v:
            row += "1"
        else:
            row += "0"
        if j != n:
            row += " "
    print(row)