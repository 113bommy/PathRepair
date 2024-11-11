s=input()
g=""
r=[]
for i in range(len(s)):
    g+=s[i]
    if g=="WUB":g=""
    elif g[-3:]=="WUB":
        r+=[g[:-3]]
        g=""
print(*r)