game_str = input()
cnt = 0
duplicate = ['']
for char in game_str:
    if char == duplicate[-1]:
        duplicate.pop()
        cnt += 1
    else:
        duplicate.append(char)
if cnt % 2 != 0:
    print('YES')
else:
    print('NO')