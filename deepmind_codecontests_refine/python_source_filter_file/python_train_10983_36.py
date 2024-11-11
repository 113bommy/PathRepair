string = input()
g, l = sum([1 for i in string if i.isupper()]), sum([1 for i in string if i.islower()])
if g > l:
    print(string.lower())
else:
    print(string.upper())
