import sys
row = list(input())

if len(row) == 1:
        print(''.join(row))
        sys.exit()

for i in range(2, len(row)):
    if len(row) == 2:
        break
    if row[i - 2] == row[i -1]:
        ch = chr(ord('a') + (ord(row[i - 1]) - ord('a')  +  1) % 26)
        if ch == row[i]:
            row[i - 1] = chr(ord('a') + (ord(ch) - ord('a') +1) % 26)
        else:
            row[i - 1] = ch
        
if( row[-1] == row[-2]):
    if(row[-2] == 'a'):
        row[-1] = 'b'
    else:
        row[-1] = 'a'

print (''.join(row))
