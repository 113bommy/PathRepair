s = input()
C = s.find('C')
F = s.rfind('F')

if -1 < C < F:
    print('Yes')
else:
    print('No')