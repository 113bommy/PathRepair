from sys import stdin

t = int(stdin.readline())

for x in range(t):
    if int(stdin.readline()) % 4 == 0:
        print('YES')
    else:
        print('NO')
