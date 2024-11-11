s = input()
n = len(s)
# 1

def check(s):
    return s==s[::-1]
ans = 10

if len(set(s))==1 or (len(s)&1 and len(set(s))==2 and (s.count(sorted(list(set(s)))[0]) == n-1 or s.count(sorted(list(set(s)))[0]) == 1)):
    print('Impossible')
else:
    for i in range(n):
        suf = s[-i-1:]
        pref = s[:-i-1]
        #print(pref, suf)
        newstr = suf+pref
        if check(newstr) and newstr!=s:
            #print(newstr, 1)
            ans = min(ans, 1)
    print(int(str(ans), 2))
