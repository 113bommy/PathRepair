N = input()
if len([a for a in input().rstrip().split() if a % 2]) % 2:
    print('NO')
else:
    print('YES')