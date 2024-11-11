instances = []

for i in range(int(input())):
    instances.append([int(i) for i in input().split()])


for m in instances:
    if m[1] * 2 < m[2]:
        print(m[0] * m[1])
    else:
        if m[0] % 2 == 0:
            print((m[0] // 2) * m[2])
        else:
            print(((m[0] - 1) // 2) * m[2] + m[1])
