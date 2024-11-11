

n = int(input())
s = input()
from collections import Counter

c = Counter(s)
if (c["B"]%2==1 and c["W"] > 0) or (c["B"] > 0 and c["W"]%2==1) and len(s)%2==0:
    print(-1)
else:
    s = list(s)
    scopy = s[:]
    targ = s[0]
    d = {"W":"B", "B":"W"}
    c = 0
    ans = []
    while len(set(s))!=1:
        #print(s)
        for i in range(len(s)-1):
            if s[i]!=targ:
                ans.append(i+1)
                s[i], s[i+1] = targ, d[s[i+1]]
                break
        c += 1
        if c > 3*len(s):
            c = 0
            targ = d[targ]
            s = scopy[:]
            ans = []
            continue
    print(c)
    print(" ".join(list(map(str,ans))))