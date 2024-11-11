import sys
n = int(sys.stdin.readline())

group_1 = []
group_2 = []
group_3 = []
for s in sys.stdin.readline().split():
    i = int(s)
    if i == 0:
        group_3.append(i)
    elif i > 0:
        group_2.append(i)
    else:
        group_1.append(i)

if len(group_1) % 2 == 0:
    group_2.append(group_1[-1])
    group_1.pop()
if len(group_2) == 0:
    group_2 = group_1[-2:]
    group_1.pop()
    group_1.pop()

print(len(group_1), ' '.join(map(str ,group_1)))
print(len(group_2), ' '.join(map(str, group_2)))
print(len(group_3), ' '.join(map(str, group_3)))
