def read():
    return int(input())


n = read()
switch = True
a = []
for i in range(n):
    line = [None] * n
    for j in range(n):
        line[j] = "B" if (i + j) % 2 == 0 else "N"
    a.append(line)

for line in a:
    print("".join(line))