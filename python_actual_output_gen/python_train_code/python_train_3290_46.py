partipants = int(input())

for i in range(partipants):
    player = input().split()
    if int(player[2]) > int(player[1]) > 2400:
        print('YES')
        exit()
print('NO')


