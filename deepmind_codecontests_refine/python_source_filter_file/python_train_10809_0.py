L = int(input())
Ss = input()
Ts = input()

if Ss > Ts:
    Ss, Ts = Ts, Ss

lenS, lenT = len(Ss), len(Ts)

for numS in reversed(range(L//lenS+1)):
    numT = (L-lenS*numS) / lenT
    if int(numT) == numT:
        ans = Ss*numS + Ts*int(numT)
        print(ans)
        break
