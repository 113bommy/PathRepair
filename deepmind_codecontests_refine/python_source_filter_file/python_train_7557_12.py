good = input()
s = input()
le = len(s)
n = int(input())
star = False
pos = s.find('*')
if pos!=-1:
    star = True
print(star)
def check(string, test):
    for i in range(len(string)):
        if string[i]=='?':
            if test[i] not in good:
                return False
        elif string[i]!=test[i]:
                return False
    return True
for i in range(n):
    t = input()
    tle = len(t)
    ans = True
    if not star:
        if tle!=le:
            ans = False
        else:
            ans = check(s,t)
    else:
        if tle>=le-1:
            ans = check(s[:pos],t[:pos])
            if ans and check(s[pos+1:],t[tle-(le-pos-1):]):
                ans = True
            else:
                ans = False
            if ans:
                for j in range(pos,tle-(le-pos-1)):
                    if t[j] in good:
                        ans = False
        else:
            ans = False
    if ans:
        print("YES")
    else:
        print("NO")
