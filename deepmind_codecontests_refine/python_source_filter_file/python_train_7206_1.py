#!/usr/bin/python

testCases = int(input())

for t in range(testCases):
    # a - column, b - row
    a, b, x, y = map(int, input().rstrip().split())

    # There will be four possible options for the maximum area
    #   On the left & right side of the pixel and on the up and bottom side of the pixel
    areaCal = dict()

    # Consider the column first
    
    areaCal.update(leftArea = b * x)
    areaCal.update(rightArea = b * (a - (x + 1)))
    areaCal.update(upArea = a * y)
    areaCal.update(downArea = a * (b - (y + 1)))

    max_area = 0
    for value in areaCal.values():
        if value > max_area:
            max_area = value
    
    print(areaCal)
    print(max_area)