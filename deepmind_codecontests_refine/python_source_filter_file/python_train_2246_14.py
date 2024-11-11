a = int(input())
b = int(input())
c = a + b
lastA = []
lastB = []
lastC = []
while a > 0:
    lastA.append(a % 10)
    a = a // 10
lastA.reverse()
while b > 0:
    lastB.append(b % 10)
    b = b // 10
lastB.reverse()
while c > 0:
    lastC.append(c % 10)
    c = c // 10
lastC.reverse()
try:
    while lastA.index(0):
        lastA.pop(lastA.index(0))
except:
    print('', end='')
try:
    while lastB.index(0):
        lastB.pop(lastB.index(0))
except:
    print('', end='')
try:
    while lastC.index(0):
        lastC.pop(lastC.index(0))
except:
    print('', end='')
lastAA = int(''.join(map(str, lastA)))
lastBB = int(''.join(map(str, lastB)))
lastCC = int(''.join(map(str, lastC)))
if lastAA + lastBB == lastCC:
    print('Yes!')
else:
    print('No!')