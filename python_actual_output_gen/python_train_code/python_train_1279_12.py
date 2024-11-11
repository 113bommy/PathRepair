s=''.join({}.fromkeys(sorted((input()))).keys())
a='abcdefghijklmnopqrstuvwxyz'
if a[:len(s)]==s:
    print('YES')
else:
    print('NO')