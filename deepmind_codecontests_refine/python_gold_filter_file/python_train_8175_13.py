# You lost the game.
s = str(input())
n = len(s)

sym = "AHIMOoTUVvWwXxY"

if n % 2 and sym.count(s[n//2]) == 0:
    print("NIE")
else:
    r = ""
    ok = 1
    for i in range(n//2):
        if sym.count(s[i]):
            r = s[i] + r
        elif s[i] == "b":
            r = "d" + r
        elif s[i] == "d":
            r = "b" + r
        elif s[i] == "p":
            r = "q" + r
        elif s[i] == "q":
            r = "p" + r
        else:
            ok = 0
            break
    if ok == 0:
        print("NIE")
    else:
        if s[n//2 + n%2:] == r:
            print("TAK")
        else:
            print("NIE")
