string = input()
if string.isupper():
    print(string.lower())
elif string[1:].isupper() and string[0].islower():
    print(string[0].upper() + string[1:].lower())
elif len(string) == 1:
    print(string.isupper())
else:
    print(string)
