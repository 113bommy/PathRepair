word = input()
if word == word.upper():
    res = word.capitalize()
    print(res)
else:
    word1 = word[1:]
    if word1 == word1.upper():
        res1 = word.capitalize()
        print(res1)
    else:
        print(word)