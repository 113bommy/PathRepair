def main():
    s, t = input(), input()
    mappingS = list(s)
    mappingT = list(t)
    yay = 0
    whoops = 0
    offset =  ord('A') - ord('a')
    for i in range(ord('a'), ord('z') + 1, 1):
        sLower = mappingS.count(chr(i))
        tLower = mappingT.count(chr(i))
        sUpper = mappingS.count(chr(i+offset))
        tUpper = mappingT.count(chr(i+offset))
        contribution = min(sLower,tLower) + min(sUpper, tUpper)
        yay += contribution
        whoops += min(tLower + tUpper, sLower + sUpper) - contribution
    print("{0} {1}".format(yay, whoops))

if __name__ == '__main__':
    main()