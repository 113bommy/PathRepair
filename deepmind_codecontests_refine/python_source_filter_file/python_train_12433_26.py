g = [input() for i in range(3)]

def findWin(x):
    global g
    if g[0][0] == g[1][1] == g[2][2] == x or g[0][2] == g[1][1] == g[2][0] == x:
        return True

    for i in range(3):
        if g[i][0] == g[i][1] == g[i][2] == x or g[0][i] == g[1][i] == g[2][i] == x:
            return True
    return False

oneWin = findWin('X')
twoWin = findWin('0')
oneCount = sum(l.count('X') for l in g)
twoCount = sum(l.count('0') for l in g)

if (oneCount > twoCount and twoWin) or (twoCount > oneCount and oneWin) or oneCount < twoCount or twoCount-oneCount > 1 or (oneWin and twoWin):
    print("illegal")
elif oneWin:
    print("the first player won")
elif twoWin:
    print("the second player won")
elif oneCount+twoCount == 9:
    print("draw")
elif oneCount == twoCount:
    print("first")
else:
    print("second")