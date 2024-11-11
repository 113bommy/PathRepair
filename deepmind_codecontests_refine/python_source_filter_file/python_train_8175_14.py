

symmetric_letters = ['A', 'H', 'I', 'M', 'O', 'o', 'U', 'V',
                     'v', 'W', 'w', 'X', 'x', 'Y']

letter_trans = {
    'b': 'd',
    'd': 'b',
    'p': 'q',
    'q': 'p',
}

for letter in symmetric_letters:
    letter_trans[letter] = letter

word = input()

if all([x in letter_trans for x in word]) and \
        list(word) == [letter_trans[x] for x in word[::-1]]:
    print("TAK")
else:
    print("NIE")
