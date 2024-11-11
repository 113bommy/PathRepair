s = input()
c = s.find('C')
f = s.find('F')
print('Yes') if c >= 0 and f >= 0 and (c - f) < 0 else print('No')