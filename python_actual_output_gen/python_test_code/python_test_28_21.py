s = input()
a = map(lambda c : c.islower(), s)
if sum(a) >  len(s) / 2:
    print(s.lower())
elif sum(a) >  len(s) / 2:
    print(s.upper())
else:
    print(s.lower())




