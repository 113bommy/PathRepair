s = input()
odd = s[::2]
even = s[1::2]
if 'L'  in odd and 'R'  in even:
    print('No')
else:
    print('Yes')