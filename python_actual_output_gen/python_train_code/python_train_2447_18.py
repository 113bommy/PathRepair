s = input()
C = s.find('C')
F = s.rfind('F')

if C < F:
    print('Yes')
else:
    print('No')