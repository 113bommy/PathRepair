s = input()
n = len(s)
d = {'a': 0, 'b': 0, 'c': 0, 'd': 0, 'e': 0, 'f': 0, 'g': 0, 'h': 0, 'i': 0, 'j': 0, 'k': 0, 'l': 0, 'm': 0, 'n': 0, 'o': 0, 'p': 0, 'q': 0, 'r': 0, 's': 0, 't': 0, 'u': 0, 'v': 0, 'w': 0, 'x': 0, 'y': 0, 'z': 0}

ltype = set()

# if s == s[::-1]:
#    print(s)
#    exit()

for i in s:
    d[i] += 1
    ltype.add(i)

if n % 2 == 0:
    oddPos = []
    oddNum = 0
    for i in range(97, 123):
        if d[chr(i)] % 2 == 1:
            d[chr(i)] -= 1
            oddNum += 1
            oddPos.append(chr(i))

    oddNum //= 2
    for i in range(oddNum):
        d[oddPos[i]] += 2

    for i in range(97, 123):
        print(chr(i) * (d[chr(i)] // 2), end='')
        d[chr(i)] //= 2

    for i in range(122, 96, -1):
        print(chr(i) * (d[chr(i)]), end='')

else:
    lnum = len(ltype)
    oddPos = []
    oddNum = 0
    for i in range(97, 123):
        if d[chr(i)] % 2 == 1:
            d[chr(i)] -= 1
            oddNum += 1
            oddPos.append(chr(i))

    oddNum = (oddNum+1)//2
    for i in range(oddNum-1):
        d[oddPos[i]] += 2

    for i in range(97, 123):
        d[chr(i)] -= d[chr(i)]//2
        print(chr(i) * d[chr(i)], end='')

    print(oddPos[oddNum-1], end='')

    for i in range(122, 96, -1):
        print(chr(i) * (d[chr(i)]), end='')