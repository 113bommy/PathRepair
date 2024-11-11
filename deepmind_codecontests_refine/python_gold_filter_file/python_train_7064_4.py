s = input()
c = s.rfind('C')
f = s.rfind('F')
print('Yes') if c >= 0 and f >= 0 and (c - f) < 0 else print('No')