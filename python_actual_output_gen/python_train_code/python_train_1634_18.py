word = input()
if word == word.upper():
    word = word.lower()
if word == (word[0].lower() + word[1:].upper()):
    word = word.title()
print(word)