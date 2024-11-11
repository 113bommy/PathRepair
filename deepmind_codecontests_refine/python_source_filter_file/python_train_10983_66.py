word = input()
countUpper = 0
countLower = 0
for i in word:
    if i.isupper() == True:
        countUpper += 1
    else: countLower += 1
    
print(word.lower()) if countLower > countUpper else print(word.upper())