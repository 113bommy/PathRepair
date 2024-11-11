s =input()
s=s.replace("WUB",' ')
s = s.strip()
while '  ' in s:
    s=s.replace('  ',' ')
print(s)
