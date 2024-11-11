from sys import stdin

t = int(stdin.readline())

for x in range(t):
    if int(stdin.readline()) % 2 == 0:
        print('YES')
    else:
        print('NO')
