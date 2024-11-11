ches = []
prog = []

for _ in range(int(input())):
    ches.append([int(el) for el in input().split()])

for _ in range(int(input())):
    prog.append([int(el) for el in input().split()])

ches.sort(key=lambda x:x[1])
prog.sort(key=lambda x:x[0])
one = prog[-1][0] - ches[0][1]

ches.sort(key=lambda x:x[0])
prog.sort(key=lambda x:x[1])
two = ches[-1][0] - prog[0][1]
prin = max(one, two)
if prin < 0:
    prin = 0
print(prin)