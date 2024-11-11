s = input()
s2 = s
i = s.find('AB')
nfound = 1
if i!=-1:
    s = s[:i] +'F'+ s[i+2:]
    if s.find('BA')!=-1: print('YES1');exit()
i = s2.find('BA')
if i!=-1:
    s2 = s2[:i] +'f'+ s2[i+2:]
    if s2.find('AB')!=-1: print('YES2');exit()
if nfound: print('NO')
        