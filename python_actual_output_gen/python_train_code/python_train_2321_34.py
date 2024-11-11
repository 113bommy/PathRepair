def nineteen_count(string):
    letter_count = {}
    for letter in string:
        if letter in letter_count:
            letter_count[letter] += 1
        else:
            letter_count[letter] = 1
    if 'n' not in letter_count or 'i' not in letter_count or 'e' not in letter_count or 't' not in letter_count:
        return 0
    return min((letter_count['n'] + 1)//3, letter_count['i'], letter_count['e']//3, letter_count['t'])

print(nineteen_count(input()))