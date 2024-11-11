import sys
fin = sys.stdin

def tanya_substract(a, s):
    s = s[::-1]
    a = a[::-1]
    
    b = []
    while s:
        c_s = s[0]
        if a == '':
            a = '0'    
        c_a = a[0]
            
        c_b = int(c_s) - int(c_a)  
        if c_b < 0:
            if len(s) >= 2 and s[1] != '1':
                return -1
            else:
                s = s[1:]
            c_b %= 10
        b.append(str(c_b))
        a = a[1:]
        s = s[1:]
    
    b = b[::-1]
    if not b:
        return -1
    return ''.join(b).lstrip('0') if a == '' and s == '' else -1
    
    
n = int(fin.readline())
for i in range(n):
    l = fin.readline().rstrip('\n')
    a, s = l.split()
    b = tanya_substract(a, s)
    print(b)