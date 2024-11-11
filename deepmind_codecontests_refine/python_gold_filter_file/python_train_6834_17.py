import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

n = int(input())
loop = [8, 0, 4, 6, 9, 1, 2, 3, 5, 7]
if not n & 1:
    eight = n // 2
    if eight > 18:
        print(-1)
    else:
        print('8' * eight)
else:
    eight = n // 2
    if eight > 17:
        print(-1)
    else:
        print('8' * eight + '4')