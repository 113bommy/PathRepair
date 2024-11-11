s = input()
v = 0
o = 0
S = []
totalv = 0
for i in range(len(s)):
    if s[i]=='v':
        v+=1
        if o and v>1:
            S.append(('o', o))
            o = 0
    if s[i]=='o':
        o+=1
        if v:
            if v>1:
                totalv += v-1
                S.append(('v', v-1))
            v = 0
if v:
    totalv += v-1
    S.append(('v', v-1))
l = []
r = []
o = []
x = 0
ans = 0
if len(S)>3:
    for i in S:
        if i[0]=='v':
            x+=i[1]
        if i[0]=='o':
            ans += x*(totalv-x)*i[1]
print(ans)
