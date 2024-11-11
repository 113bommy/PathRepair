s=str(input())
t=str(input())
s=s[::-1]
t=t[::-1]
ns=len(s)
nt=len(t)
i=0
res=ns+nt
if min(ns,nt)==1:
    if s[0]==t[0]:
        res=max(ns,nt)-1
else:
    while (t[i]==s[i]):
        res-=2
        i=i+1
        if i+1==min(ns,nt):
            break

print(res)