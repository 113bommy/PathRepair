s = input()
print('YES' if s.count('o') != 0 and s.count('-') % s.count('o') is 0 else 'NO')
