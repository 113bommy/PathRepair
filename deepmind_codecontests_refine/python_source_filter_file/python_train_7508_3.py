def checkPali(s):
    for i in range(len(s)):
        if s[i] != s[len(s) - i - 1]:
            return False
    return True

def check(s):
    for i in range(len(s)):
        s2 = s[i : ] + s[ : i]
        if checkPali(s2) and s != s2:
            return i

def checkOdd(s):
    for i in range(1, len(s) // 2):
        if s[i] != s[i - 1]:
            return False
    return True

s = input()
flag = True
if len(s) == 1:
    flag = False
elif len(s) % 2 != 0 and checkOdd(s):
    flag = True
else:
    for i in range(1, len(s)):
        if s[i] != s[i - 1]:
            flag = False
if flag:
    print("Impossible")
elif check(s):
    print(1)
else:
    print(2)