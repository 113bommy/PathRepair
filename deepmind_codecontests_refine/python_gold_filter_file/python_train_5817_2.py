s=''
for c in input():s=[s+c,s[:-1]][c=='B']
print(s)