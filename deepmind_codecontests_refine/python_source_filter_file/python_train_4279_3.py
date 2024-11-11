#E48_B

ln = [int(i) for i in input().split(" ")]
n = ln[0]
m = ln[1]
q = ln[2]

s = input()
t = input()

def runAns(s, t):
    ss = 0
    sso = [0] * (len(t) - 1)

    for i in range(0, n - len(t) + 1):
        f = True
        for j in range(0, n - i):
            if j >= len(t):
                break
            if s[i + j] != t[j]:
                f = False
                break
        if f:
            ss += 1
        sso.append(ss)


    return [ss, sso]

o = runAns(s, t)
ss = o[0]
o1 = o[1]
o = runAns("".join(list(s)[::-1]), "".join(list(t)[::-1]))
o2 = o[1][::-1]

for i in range(0, q):
    ln = [int(j) for j in input().split(" ")]
    n1 = ln[0]
    n2 = ln[1]
    print(o2[n1 - 1] + o1[n2 - 1] - ss)
