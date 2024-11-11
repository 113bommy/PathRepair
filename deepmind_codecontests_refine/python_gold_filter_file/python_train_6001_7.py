#n = int(input())
n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
a = []
a.append('#' * (m + 2)) 
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == 'S':
            g = i + 1
            h = j + 1
    a.append('#' + s + '#')
a.append('#' * (m + 2))
b = []
b.append(['U', 'D', 'R', 'L'])
b.append(['U', 'D', 'L', 'R'])
b.append(['U', 'R', 'L', 'D'])
b.append(['U', 'R', 'D', 'L'])
b.append(['U', 'L', 'D', 'R'])
b.append(['U', 'L', 'R', 'D'])

b.append(['D', 'U', 'R', 'L'])
b.append(['D', 'U', 'L', 'R'])
b.append(['D', 'R', 'L', 'U'])
b.append(['D', 'R', 'U', 'L'])
b.append(['D', 'L', 'U', 'R'])
b.append(['D', 'L', 'R', 'U'])

b.append(['L', 'U', 'R', 'D'])
b.append(['L', 'U', 'D', 'R'])
b.append(['L', 'R', 'D', 'U'])
b.append(['L', 'R', 'U', 'D'])
b.append(['L', 'D', 'U', 'R'])
b.append(['L', 'D', 'R', 'U'])

b.append(['R', 'U', 'D', 'L'])
b.append(['R', 'U', 'L', 'D'])
b.append(['R', 'D', 'L', 'U'])
b.append(['R', 'D', 'U', 'L'])
b.append(['R', 'L', 'U', 'D'])
b.append(['R', 'L', 'D', 'U'])

s = input()
l = len(s)
z = 0
for i in range(24):
    x = g
    y = h
    for j in range(l):
        p = int(s[j])    
        if b[i][p] == 'U':
            x += 1
        elif b[i][p] == 'D':
            x -= 1
        elif b[i][p] == 'L':
            y -= 1
        else:
            y += 1
        if a[x][y] == 'E':
            z += 1
            break
        if a[x][y] == '#':
            break
print(z)