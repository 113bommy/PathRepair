count = 12
ans = False
first = [list(input())]
first.append(list(input()))
second = [list(input())]
second.append(list(input()))
for i in range(count):
    if first == second:
        ans = True
        break
    if first[0][0] == 'X':
        first[0][0], first[0][1] = first[0][1], first[0][0]
    elif first[0][1] == 'X':
        first[0][1], first[1][1] = first[1][1], first[0][1]
    elif first[1][1] == 'X':
        first[1][1], first[1][0] = first[1][0], first[1][1]
    elif first[1][0] == 'X':
        first[1][0], first[0][0] = first[0][0], first[1][0]

if ans:
    print('YES')
else:
    print('NO')