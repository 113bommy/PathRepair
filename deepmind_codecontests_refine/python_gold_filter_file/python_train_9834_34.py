
k = int(input())
s = [list('+------------------------+'),
     list('|#.#.#.#.#.#.#.#.#.#.#.|D|)'),
     list('|#.#.#.#.#.#.#.#.#.#.#.|.|'),
     list('|#.......................|'),
     list('|#.#.#.#.#.#.#.#.#.#.#.|.|)'),
     list('+------------------------+')]

row = 1
c = 1
for i in range(k):
    s[c][row] = 'O'
    c += 1

    if row > 1 and c == 3:
        c += 1
    if c == 5:
        c = 1
        row += 2
        
for i in range(6):
    print(''.join([ss for ss in s[i]]))