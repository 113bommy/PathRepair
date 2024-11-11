def prefix(s):
    v = [0]*len(s)
    for i in range(1,len(s)):
        k = v[i-1]
        while k > 0 and s[k] != s[i]:
            k = v[k-1]
        if s[k] == s[i]:
            k = k + 1
        v[i] = k
    return v

def kmp(s,t):
    index = -1
    f = prefix(s)
    k = 0
    for i in range(len(t)):
        while k > 0 and s[k] != t[i]:
            k = f[k-1]
        if s[k] == t[i]:
            k = k + 1
        if k == len(s):
            index = i - len(s) + 1
            break
    return index

def inp(cin):
    for i in ";_-": inp = cin.replace(i,"")
    return cin.lower()

inp1,n = [inp(input()) for i in range(3)],int(input())
inp2 = [inp(input()) for i in range(n)]
inp3 = [inp1[0]+inp1[1]+inp1[2],inp1[0]+inp1[2]+inp1[1],inp1[1]+inp1[0]+inp1[2],
        inp1[1]+inp1[2]+inp1[0],inp1[2]+inp1[1]+inp1[0],inp1[2]+inp1[0]+inp1[1],]
for i in inp2:
    iii = 0
    for z in inp3:
        if kmp(i,z) >= 0 and len(i) == len(z):
           iii = 1
           break
    print("WA" if iii == 0 else "ACC")