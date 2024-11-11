s = input()
print('AC' if 'A' in s and 'C' in s and s[1:].replace('C','',1).islower() else 'WA')