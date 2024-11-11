def getWiner(args):
    first = int(args[0]) * int(args[1]) + int(args[3]) * 2
    second = int(args[0]) * int(args[2]) + int(args[4]) * 2
    return 'first' if first < second else 'second' if second < first else 'friendship'
print(getWiner(input().split(' ')))