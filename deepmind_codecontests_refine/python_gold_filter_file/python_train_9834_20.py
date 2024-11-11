k = int(input())

bus = "+------------------------+\n|#.#.#.#.#.#.#.#.#.#.#.|D|)\n|#.#.#.#.#.#.#.#.#.#.#.|.|\n|#.......................|\n|#.#.#.#.#.#.#.#.#.#.#.|.|)\n+------------------------+"

first1 = 28
first2 = 56
first3 = 83
first4 = 110

line = 1
for i in range(k):
    if line == 1:
        bus = bus[:first1] + 'O' + bus[first1+1:]
        first1+=2
        line = 2
    elif line == 2:
        bus = bus[:first2] + 'O' + bus[first2+1:]
        first2+=2
        if i < 4:
            line = 3
        else:
            line = 4
    elif line == 3:
        bus = bus[:first3] + 'O' + bus[first3+1:]
        line = 4
    elif line == 4:
        bus = bus[:first4] + 'O' + bus[first4+1:]
        first4+=2
        line = 1

print(bus)
