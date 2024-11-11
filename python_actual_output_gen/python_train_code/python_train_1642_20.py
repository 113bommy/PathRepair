s = input()    
cel = ''
alp = 'abcdefghijkmnlopqrstuwxyzABCDEFGHIJKMNLOPQRSTUWXYZ'
for i in range(len(s)-1, 0, -1):
    if s[i] in alp:
        cel += s[i]
        break
if cel == '':
    print('NO')
else: 
    if cel in "aeiouyAEIOUY":
        print('YES')
    else:
        print('NO')