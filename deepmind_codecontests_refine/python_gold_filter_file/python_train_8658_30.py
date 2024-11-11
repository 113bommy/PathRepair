a=input()
s=int(a[:a.index(' ')])
b=a[a.index(' ')+1:]
mi=int(b[:b.index(' ')])
ma=int(b[b.index(' '):])
aa=0
bb=0
cur=1
for k in range(s):
    aa+=cur
    if ma>1:
        cur*=2
        ma-=1
cur=int(2**(mi-1))
for k in range(s):
    bb+=int(cur)
    if cur!=1:
        cur/=2
print(min(bb,aa),max(bb,aa))
