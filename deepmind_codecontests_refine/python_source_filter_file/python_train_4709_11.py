x = input()
if x == x.upper():
    print(x.capitalize())
elif x == x[0].lower() + x[1: len(x)].upper():
    print(x.capitalize())
else:
    print(x)