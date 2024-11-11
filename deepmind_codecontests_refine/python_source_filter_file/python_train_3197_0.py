input()
s = '0' + input() + '0'
if '11' in s:
    print('No')
    exit()
if '000' in s:
    print('Yes')
    exit()
print('No')