s = input()
print('AC' if s[1] == 'A' and 'C' in s[3:-1] and s[1:].replace('C','',1).islower() else 'WA')