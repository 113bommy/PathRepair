word = input()
if word.isupper():
  word = word.lower()
elif word.islower() and len(word) > 1:
  word = word.upper()
elif word[0].islower() and word[1::].isupper():
  word = word[0].upper() + word[1::].lower()
print(word)