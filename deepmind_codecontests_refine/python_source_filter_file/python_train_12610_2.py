n = int(input())
s = input()
c = {0: s.count('0'), 1: s.count('1'), 2: s.count('2')}
p = list(s)
for i in range(n):
    if s[i] == '2' and c[2] > n/3:
        if c[0] < n/3:
            p[i] = '0'
            c[2], c[0] = c[2]-1, c[0]+1
        else:
            p[i] = '1'
            c[2], c[1] = c[2]-1, c[1]+1
    elif s[i] == '1' and c[1] > n/3:
        if c[0] < n/3:
            p[i] = '0'
            c[1], c[0] = c[1]-1, c[0]+1
for i in range(n-1,-1,-1):
    if s[i] == '0' and c[0] > n/3:
        if c[2] < n/3:
            p[i] = '2'
            c[2], c[0] = c[2]+1, c[0]-1
        else:
            p[i] = '1'
            c[1], c[0] = c[1]+1, c[0]-1
    elif s[i] == '1' and c[1] > n/3:
        if c[2] < n/3:
            p[i] = '2'
            c[2], c[0] = c[2]+1, c[0]-1
print(''.join(p))

