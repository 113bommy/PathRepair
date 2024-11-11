def addString(a, b):
    ia = len(a) - 1
    ib = len(b) - 1
    re = 0
    ans = []
    
    while ia >=0 or ib >= 0:
        cur = re
        if ia >= 0: cur += int(a[ia])
        if ib >= 0: cur += int(b[ib])
        if cur >= 10:
            re = 1
        else:
            re = 0
        ans += str(cur % 10)
        ia -= 1
        ib -= 1
    ans = ans[::-1]
    return ("".join(ans))

F, S = input().split(".")

if F[-1] == '9':
    print("GOTO Vasilisa.")
else:
    if int(S[0]) < 5:
        print(F)
    else:
        print(addString(F, "1")) 