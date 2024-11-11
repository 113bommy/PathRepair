import itertools

k = int(input())

spots = [(1,1),(2,1),(3,1),(4,1)] + \
    list(itertools.chain.from_iterable([[(1,i),(2,i),(4,i)] for i in range(3,23,2)]))

bus = ['']*6
bus[0] = list("+------------------------+" )
bus[1] = list("|#.#.#.#.#.#.#.#.#.#.#.|D|)")
bus[2] = list("|#.#.#.#.#.#.#.#.#.#.#.|.|" )
bus[3] = list("|#.......................|" )
bus[4] = list("|#.#.#.#.#.#.#.#.#.#.#.|.|)")
bus[5] = list("+------------------------+" )

for i in range(k):
    r,c = spots[i]
    bus[r][c] = 'O'

for b in bus:
    print(''.join(b))