a = int(input())

for i in range(a):
    c, d = [int(i) for i in input().split()[1:]]
    if c > 2400 and d > c:
        print('YES')
        break
else:
    print('NO')
