def charToInt(c): #'a'->0
    return ord(c)-ord('a')
def intToChar(x): #0->'a'
    return chr(ord('a')+x)

s=input()
t=input()

#tt=[charToInt(c) for c in t]
ss=[charToInt(c) for c in s]
n=len(ss)

for i in range(n-1,-1,-1):
    ss[i]+=1
    if ss[i]==26:
        ss[i]-=26
    else:
        break

s=''.join([intToChar(x) for x in ss])
if s>=t:
    print('No such string')
else:
    print(s)