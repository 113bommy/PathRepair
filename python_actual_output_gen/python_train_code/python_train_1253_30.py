s = input()
if s[0] == 'A' and s[2:-1].count('C') == 1 and sum(_==_.upper() for _ in s):
    print('AC')
else:
    print('WA')