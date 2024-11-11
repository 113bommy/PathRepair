a, b = input(), input()
x, y = a.count('1'), b.count('1')
print('YNEOS'[x + (x & 1) < y :: 2])