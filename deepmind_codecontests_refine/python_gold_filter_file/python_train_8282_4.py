n,leng=map(int,input().split())
a=leng
d=leng
c=leng
from re import search
e=[[],[],[],[]]
for i in range(n):
    s=input()
    sr=s[::-1]
    let=search('[a-z]',s)
    dig=search('\d', s)
    sig=search('\*|#|&', s)
    if let:
        let=min(let.start(),search('[a-z]',sr).start()+1)
        e[1].append([let, i])
    if dig:
        dig = min(dig.start(), search('\d', sr).start() + 1)
        e[2].append([dig, i])
    if sig:
        sig = min(sig.start(), search('\*|#|&', sr).start() + 1)
        e[3].append([sig, i])
    if len(e[1])>3:
        e[1].sort()
        e[1].pop()
    if len(e[2])>3:
        e[2].sort()
        e[2].pop()
    if len(e[3])>3:
        e[3].sort()
        e[3].pop()
ans=leng*3
e.pop(0)
def rec(se,ind):
    if len(se)==3:
        global ans
        ans=min(ans,sum(se))
    else:
        for el,i in e[len(se)]:
            if i not in ind:
                rec(se+[el],ind|{i})
rec([],set())
print(ans)