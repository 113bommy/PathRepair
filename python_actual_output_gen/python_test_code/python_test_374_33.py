n = int(input())
s = input()
z = 0
k = 0
for i in range(0, n):
    if s[i] == 'z':
        z = z + 1
    if s[i] == 'n':
        k = k + 1
while k != 0 :
    k = k - 1
    print('1', end = '')
while z != 0 :
    z = z - 1
    print('0', end = '')
