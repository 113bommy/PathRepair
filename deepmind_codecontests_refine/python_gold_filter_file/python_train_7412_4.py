t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if 2*a-b >= 0 and 2*b-a >= 0 and (2*a-b) % 3 == 0:
        print('YES')
    else:
        print('NO')
