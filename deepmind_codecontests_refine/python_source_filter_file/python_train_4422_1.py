import operator


n = int(input())
xs = list(map(int, str.split(input())))
if xs == sorted(xs):

    print(0)

else:

    swaps = []
    counter = 0
    while xs:

        i = xs.index(min(xs))
        if i:

            swaps.append(str.format("{} {}", counter, i + counter))

        xs[0], xs[i] = xs[i], xs[0]
        xs.pop(0)
        counter += 2

    print(len(swaps))
    print(str.join("\n", swaps))