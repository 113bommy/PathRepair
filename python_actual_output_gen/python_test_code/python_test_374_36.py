a = int(input())
b = str(input())
g =[]
for i in range(0, len(b)-1):
    if b[i] == "z":
        g.append(0)
    if b[i] == "n":
        g.append(1)
g.sort()
g.reverse()
print(*g)