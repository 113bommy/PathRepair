import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
for _ in range(int(input())):
    n,m=[int(x) for x in input().split()]
    if n%m==0:
        print('YES')
    else:
        print('NO')