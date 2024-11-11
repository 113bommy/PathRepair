size = int(input())
word = list(input())

def isConsecutiveVowels(ch1, ch2):
    return (ch1 in "aeiou") and (ch2 in "aeiou")

for i in range(1, size):
    
    if isConsecutiveVowels(word[i], word[i-1]):
        word[i] = ''
    

print(''.join(word))
