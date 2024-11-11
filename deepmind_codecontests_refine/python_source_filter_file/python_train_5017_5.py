from sys import stdin

def solve(enterOrder, leaveOrder, x):
    enterOrderMap = {}
    leaveOrderMap = {}

    for i in range(x):
        enterOrderMap[enterOrder[i]] = i

    for i in range(x):
        leaveOrderMap[leaveOrder[i]] = i

    count = 0
    last = 0

    for key in enterOrder:
        if(enterOrderMap[key] < leaveOrderMap[key] and leaveOrderMap[key] > last):
            count += leaveOrderMap[key] - last
            last = leaveOrderMap[key] + 1

    return count

x = int(input())
enterOrder = list(map(int, stdin.readline().rstrip().split()))
leaveOrder = list(map(int, stdin.readline().rstrip().split()))
print(solve(enterOrder, leaveOrder, x))

