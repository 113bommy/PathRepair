n = int(input())
s = input()
b = s.count('B')
r = s.count('R')
g = s.count('G')
if 'B' in s and 'G' in s and 'R' in s:
    print('BGR')
elif s == 'B' * n:
    print('B')
elif s == 'G' * n:
    print('G')
elif s == 'R' * n:
    print('R')
elif 'B' not in s:
    if g == r == 1:
        print('B')
    elif g > 1 and r > 1:
        print('BGR')
    elif g == 1 and r > 1: #grr br g; grr gr b
        print('BG')
    elif g > 1 and r == 1:
        print('BR')
elif 'G' not in s:
    if b == r == 1:
        print('G')
    elif b > 1 and r > 1:
        print('BGR')
    elif b == 1 and r > 1: # brr gr b; brr br g
        print('BG')
    elif b > 1 and r == 1: # bbr br g; bbr bg r;
        print('GR')
elif 'R' not in s:
    if b == g == 1:
        print('R')
    elif b > 1 and g > 1:
        print('BGR')
    elif b == 1 and g > 1:
        print('BR')
    elif g > 1 and r == 1:
        print('GR')
