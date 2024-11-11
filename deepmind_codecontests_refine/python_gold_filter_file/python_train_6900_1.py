t = input()
a, b = int(t[0] == '-'), t.find('.')
if b < 0:
    b = len(t)
    t += '.'
c = (b - a) % 3
print('(' * a + '$' + t[a: a + c] + ',' * (b - a > 2 and c > 0) + ','.join(t[i: i + 3] for i in range(a + c, b, 3)) + (t[b:] + '00')[: 3] + ')' * a)