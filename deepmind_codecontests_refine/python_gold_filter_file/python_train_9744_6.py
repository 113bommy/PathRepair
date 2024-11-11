'''
Created on May 20, 2017
@author: suris
'''
from functools import reduce

def main():
    # get metadata
    inputs = input().split(" ")

    n = int(inputs[0])
    maxMarks = int(inputs[1])
    reqAvg = maxMarks - 0.5

    currentTotal = reduce((lambda x, y: y + x), list(map(lambda x: int(x), input().split(" "))))

    average = 0
    result = -1

    while(average < reqAvg):
        result += 1
        average = (currentTotal + (maxMarks * result)) / (n + result)

    print(result)


if __name__ == '__main__':
    main()
