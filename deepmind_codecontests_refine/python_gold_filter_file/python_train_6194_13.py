from sys import stdin

n = int(stdin.readline())
a = min(list(map(int, stdin.readline().split())))

if a == 1:
    print (-1)
else:
    print (1)