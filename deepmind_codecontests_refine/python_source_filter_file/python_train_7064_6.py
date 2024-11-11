s = input()
x = s.index('C')
y = s.rindex('F')
if x >= 0 and y >= 0 and x < y:
    print('Yes')
else:
    print('No') 