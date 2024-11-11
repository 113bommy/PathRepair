import sys

line = sys.stdin.readline().strip()
#line = "47"

def run(i, nFour, nSeven, s, added):
    #print(i, nFour, nSeven, s, added)
    n = len(line)
    if i == n:
        print(s)
        return True

    v = ord(line[i]) - ord('0')
    if (added or v <= 4) and nFour > 0:
        if run(i + 1, nFour - 1, nSeven, s + '4', added or v < 4):
            return True
            
    if (added or v <= 7) and nSeven > 0:
        if run(i + 1, nFour, nSeven - 1, s + '7', added or v < 7):
            return True

    return False

while True:
    n = len(line)
    if n % 2 == 1:
        line = '1' + line
        n = n + 1

    v = ord(line[0]) - ord('0')
    if v <= 4:
        if run(1, n/2-1, n/2, '4', v < 4):
            break
    if v <= 7:
        if run(1, n/2, n/2-1, '7', v < 7):
            break
    line = '1'+line
    


