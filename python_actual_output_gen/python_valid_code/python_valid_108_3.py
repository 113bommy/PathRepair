s = input()
t = input()

m = [list(s), list(t)]

i = 0


ans = 0
while i < len(s) - 1:
    indexes = [(0, i), (1, i), (0, i + 1), (1, i + 1)]
    for j in range(4, -1, -1):
        flag = True
        for k in range(4):
            if k != j:
                x = indexes[k]
                if m[x[0]][x[1]] == "X":
                    flag = False
                    break
        if flag:
            for k in range(4):
                if k != j:
                    x = indexes[k]
                    m[x[0]][x[1]] = "X"
            ans += 1
            break
    i += 1

print(ans)