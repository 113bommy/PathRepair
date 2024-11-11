word = input()

if word.upper() == word:
    print(word)
elif word[1:].upper() == word[1:] and word[0].lower() == word[0]:
    word = word[0].upper() + word[1:].lower()
    print(word)
else:
    print(word)