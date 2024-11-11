s =input()
s=s.replace("WUB",' ')
s = s.strip()
print(s)
while '  ' in s:
    s=s.replace('  ',' ')
print(s)
