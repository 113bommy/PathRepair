s = str(input())
if s[0] == 'A' and s[2:-1].count('C') == 1 and (s[2:s.find('C')]+s[s.find('C')+1:]).islower():
    print('AC')
else:
    print('WA')