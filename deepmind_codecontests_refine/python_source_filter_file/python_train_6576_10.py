from collections import Counter
def solve(s,t,p):
    if len(s) > len(t):
        return 0
    if len(s)==len(t):
        if s==t:
            return 1
        else:
            return 0
    s1,p1 = Counter(s),Counter(p)
    d1 = s1 + p1
    d2 = Counter(t)
    for i in d2.keys():
        if d1.get(i) == None :
            return 0
        if d1.get(i) and d1[i]< d2[i]:
            return 0
    for key in s1.keys():
        if d2.get(key) == None:
            return 0
    k = 0
    for i in range(len(s)):
        ok = True
        for j in range(k,len(t)):
            if s[i] == t[j]:
                ok = False
                k = i+1
                break
        if ok:
            return 0
        
    return 1

t = int(input())
for _ in range(t):
    s = input()
    t = input()
    p = input()
    if solve(s,t,p):
        print("YES")
    else:
        print("NO")