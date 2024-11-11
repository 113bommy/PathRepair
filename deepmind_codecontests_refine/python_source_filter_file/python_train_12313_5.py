# Strategy:  Based on y coordinate throwing position, determine whether it is
# a single or double.  then calculate area and determine if point is strictly inside


def determineArea(a, x, y):

    squarePos = y // a + 1
    lowerLimit = (squarePos - 1) * a
    upperLimit = (squarePos) * a
    # X coordinates
    if squarePos | 1 == squarePos and squarePos > 2:
        double = True
        leftLimit = -a
        rightLimit = a
    else:
        double = False
        leftLimit = -(a / 2)
        rightLimit = a / 2

    if leftLimit < x < rightLimit and lowerLimit < y < upperLimit:
        if double:
            base = int(squarePos * 1.5)
            if leftLimit < x < 0:
                return base
            elif 0 < x < rightLimit:
                return base + 1
            else:
                return -1

        else:
            if squarePos < 3:
                return squarePos
            else:
                return squarePos * 1.5 - 1
    else:
        return -1


inp = [int(i) for i in str(input()).split(" ")]
a = inp[0]
x = inp[1]
y = inp[2]
print(int(determineArea(a, x, y)))
