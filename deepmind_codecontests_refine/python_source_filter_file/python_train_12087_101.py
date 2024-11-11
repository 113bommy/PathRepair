from sys import stdin

first = stdin.readline()
first = int(first)

second = map(int, stdin.readline().split())
liste = list(second)

if 1 in liste:
    print('EASY')
else:
    print('HARD')
