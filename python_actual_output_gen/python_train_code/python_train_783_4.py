#n = int(input())
n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
x = s.find('G')
y = s.find('T')
if x < y:
    x, y = y, x
if (y - x) % m == 0:
    for i in range(x + m, y, m):
        if s[i] == '.':
            print('NO')
            break
    else:
        print('YES')
else:
    print('NO')