n= int(input())
s = str(input())
z=0
o=0
for i in range(len(s)):
    if s[i] == 'z':
        z=z+1
    elif s[i] == 'n':
        o=o+1
for j in range(z):
    print('0', end=' ')
for k in range(o):
    print('1', end=' ')