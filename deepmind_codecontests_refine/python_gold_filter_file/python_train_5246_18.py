n = int(input())
s = list(input())
r = s.count('R')
l = s.count('L')
if 'R' not in s:
    for i in range(n-1, 0, -1):
        if s[i] == 'L':
            print(i+1, end=' ')
            break
    for i in range(n):
        if s[i] == 'L':
            print(i)
            exit()
if 'L' not in s:
    for i in range(n):
        if s[i] == 'R':
            print(i+1, end=' ')
            break
    for i in range(n-1, 0, -1):
        if s[i] == 'R':
            print(i+2)
            exit()
for i in range(n):
    if s[i] == 'R':
        inxr = i
        break
for i in range(n):
    if s[i] == 'L':
        inxl = i
        break
print(inxr+1, inxl)