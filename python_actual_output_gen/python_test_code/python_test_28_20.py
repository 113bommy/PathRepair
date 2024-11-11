word = input()

low_count = len([c for c in word if c.isupper()])

if (2*low_count < len(word)):
    print(word.lower())
else:
    print(word.upper())
