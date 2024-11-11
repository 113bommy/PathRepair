def isGoodOrNot(word):
    frequencyOfA = 0
    for character in word:
        if character == 'a':
            frequencyOfA = frequencyOfA+1
    if frequencyOfA/len(word) > 0.5:
        return len(word)
    else:
        length = len(word)-1
        while(frequencyOfA/length <= 0.5):
            length = length-1
        return length

    






word = input()
print(isGoodOrNot(word))
