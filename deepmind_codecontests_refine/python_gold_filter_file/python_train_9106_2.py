import math
def prefix(t,p):
    k = 0
    for i in range(1,len(t)):
        k = p[i-1]
        while ((k > 0) and (t[k+1] != t[i])):
            k = p[k]
        if (t[k+1] == t[i]):
            k = k + 1
        p[i] = k


def search_podstroki(s,t):
    t1 = t + '$' + s
    p = [-1] * (len(t1))
    prefix(t1,p)
    c1 = 0
    set_ = {}
    for i in range(1,len(t1)):
        if (p[i] == len(t)-1):
            c1 = -1
    if (c1 == -1):
        return True
    else:
        return False




def ispalindrome(l,r,s,x):
    m = math.floor((l + r) / 2)
    if (m < 1):
        r = r * 2
        s1 = s[l:round(r/2)]
        s2 = s[round(r/2):r]
        if (search_podstroki(s1,s2) == True):
            x = k
    elif ((l + r) % 2 == 0):
        s1 = s[l:m]
        s2 = s[m:r]
        s2 = s2[::-1]
        if (search_podstroki(s1,s2) == True):
            x = x + 1
    else:
        s1 = s[l:m]
        s2 = s[m+1:r]
        s2 = s2[::-1]
        if (search_podstroki(s1,s2) == True):
            x = x + 1
    return x
        


s = input()
k = int(input())
x = 0
s.rstrip()
if ((len(s)) % k != 0):
    print('NO')
elif (len(s) == k):
    print('YES')
else:
    h = round((len(s)) / k)
    r = 0
    i = 0
    while (i <= len(s)):
        l = r
        r = l + h
        x = ispalindrome(l,r,s,x)
        i = r
    if (x == k):
        print('YES')
    else:
        print('NO')