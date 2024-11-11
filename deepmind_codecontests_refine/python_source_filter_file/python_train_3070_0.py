s1 = input()
s2 = input()

r = sum(1 for i in range(len(s1)) if s1[i] != s2[i])

if r % 2 != 0:
    print('impossible')
else:
    one = True
    r = []
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            r.append(s1[i])
        else:
            if one :
                r.append('1')
                one = False
            else :
                r.append('0')
                one = True
    print(''.join(r))
