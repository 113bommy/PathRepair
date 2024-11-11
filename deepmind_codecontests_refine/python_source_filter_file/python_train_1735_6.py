# _
#####################################################################################################################

def main():
    n, sequence = input(), set(map(int, input().split()))
    firstElement = nThrees = 0
    for element in sequence:
        value = element
        for i in range(39):
            if value%3:
                if nThrees < i:
                    firstElement, nThrees = element, i
                break
            value //= 3

    if nThrees == 0:
        return ' '.join(map(str, sequence))

    return ' '.join(map(str, rearrangeElements(sequence, firstElement)))


def rearrangeElements(sequence, firstElement):
    newSequence = []
    if not firstElement%2:
        elementBeforeFirst = firstElement//2
        while elementBeforeFirst in sequence:
            newSequence.append(elementBeforeFirst)
            elementBeforeFirst //= 2

    newSequence.reverse()
    while True:
        if firstElement not in sequence:
            return newSequence
        while firstElement in sequence:
            newSequence.append(firstElement)
            firstElement *= 2
        firstElement //= 6


if __name__ == '__main__':
    print(main())
    # main()
