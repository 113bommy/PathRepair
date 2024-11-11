from sys import stdin, exit
n = int(stdin.readline().rstrip())
x = y = z = 0

for line in stdin.readlines():
    tx, ty, tz = map(int, line.rstrip().split(' '))
    x += tx; y += ty; z += tz
    
if tx != 0 or ty != 0 or tz != 0:
    print('NO')
else:
    print('YES')
    