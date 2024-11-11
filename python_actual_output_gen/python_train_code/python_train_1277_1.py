n = int(input())
s = input()
l = []
v = [0,0,0]

def val(c):
    if c == 'B':
        return 0
    elif c == 'G':
        return 1
    else:
        return 2

for c in s:
    l += [val(c)]
    v[val(c)] += 1
    
if (len(set(l))) == 3:
    print('BGR')
elif (len(set(l))) == 1:
    print(s[0])
else:
    if v[0] == 1 or v[1] == 1 or v[2] == 1:
        a = ''
        if v[0] == 0:
            a = 'B'
        elif v[1] == 0:
            a = 'G'
        else:
            a = 'R'
        if max(v) > 1:
            if v[0] == 1:
                a += 'B'
            elif v[1] == 1:
                a += 'G'
            else:
                a += 'R'
        for c in a:
            print(c,end='')
    else:
        print('BGR')
