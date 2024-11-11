s = input()
if 'C' in s and 'F' in s and s.index('C') < s.rindex('F'):
    print('Yes')
else:
    print('No')