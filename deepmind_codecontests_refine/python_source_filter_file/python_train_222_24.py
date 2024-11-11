n = int(input())
s = input()

if s.count('0') != s.count('1'):
    print(1)
    print(s)
    
else:
    a = s[n-1]
    b = list(s)
    b.pop()
    b = ''.join(b)
    c = ' '.join([a, b])
    
    print(2)
    print(c)
