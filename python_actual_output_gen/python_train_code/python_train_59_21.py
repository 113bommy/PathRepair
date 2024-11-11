import sys
a = b = 0
for m in sys.stdin:
    a += m[0] == '+'
    a -= m[0] == '-'
    b += (':' in m)*(len(m) - m.find(':') - 1) * a
print(b)