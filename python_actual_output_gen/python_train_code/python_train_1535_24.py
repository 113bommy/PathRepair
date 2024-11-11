letter = set(input().replace(' ', '').strip('{} ').split(','))

if letter is {''}:
    print(0)
else:
    print(len(letter))