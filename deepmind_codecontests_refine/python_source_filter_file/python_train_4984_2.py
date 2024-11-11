string = 'abcdefghijklmnopqrstuvwxyz'
table = []
for i in string:
    table.append(i)

def encode(string,a,b):
    data = list(string)
    s = []
    flag = 0
    for c in data:
        try:
            i = table.index(c)
            tmp = (a*i+b)%26
            s[-1:] += table[tmp]
        except:
            s.append(' ')
    s = ''.join(s)
    return s

n = int(input())
for i in range(n):
    code = str(input())
    for a in range(1,26):
        for b in range(1,26):
            s = encode(code,a,b)
            if 'that' in s:
                print(s)
                break
            elif 'this' in s:
                print(s)
                break