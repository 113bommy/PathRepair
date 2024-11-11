s = input()
if s.isupper():
    print(s.lower())
elif s[0].islower() and len(s) < 2:
    print(s[0].upper())
elif s[0].islower() and s[1:].isupper() and len(s) >2:
    print(s[0].upper() + s[1:].lower())
else:
    print(s)