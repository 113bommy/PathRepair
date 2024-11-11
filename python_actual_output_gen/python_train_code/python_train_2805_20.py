from sys import stdin, stdout

#n number of cells
#t destination
#s step

n, t = [int(c) for c in stdin.readline().split()]
s = [int(c) for c in stdin.readline().split()]

#p position

p = 1
while True:
    p = p + s[p]
    if p == t-1:
        print('YES')
        break
    elif p >= t:
        print('NO')
        break
