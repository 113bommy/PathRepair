s = input()
x = s.find('C')
y = s.rfind('F')
if x >= 0 and y >= 0 and x < y:
    print('Yes')
else:
    print('No') 