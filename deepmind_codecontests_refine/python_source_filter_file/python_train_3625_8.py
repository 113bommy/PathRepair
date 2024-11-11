s = input()
print('AC' if s[1] == 'A' and 'C' in s[2:-1] and s[1:].replace('C','',1).islower() else 'WA')