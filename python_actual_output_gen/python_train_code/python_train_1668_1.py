from sys import stdin

for case in range(int(stdin.readline())):
    n = int(stdin.readline())
    s = stdin.readline().split()

    diff = 0
    maxDiff = 0

    for x in s:
        if x == '(':
            diff += 1
        else:
            diff -= 1
        maxDiff = min(diff, maxDiff)
    print(-maxDiff)
