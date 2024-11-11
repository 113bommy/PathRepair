s = input()
print('AC' if s[0] == 'A' and 'C' in s[2:-1] and s[1:].replace('C', '').islower() else 'WA')
