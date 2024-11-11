s = input()

if s[0] == 'A' and 'C' in s[2:-2] and s[1:].replace('C', '',1).islower():
    print('AC')
else:
    print('WA')
