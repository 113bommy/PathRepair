input()
line = input()
sm = 0
res = ""
for i in range(1, 12):
    if sm >= len(line):
        break
    res += line[sm]
    sm += i
print(res)