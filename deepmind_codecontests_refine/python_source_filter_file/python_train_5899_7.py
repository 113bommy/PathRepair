import re
s=input()
try:
    print('YES' if re.match(r'aa*bb*cc*',s).group(0)==s and s.count('a')==s.count('c') or s.count('b')==s.count('c') else 'NO')
except:
    print('NO')
