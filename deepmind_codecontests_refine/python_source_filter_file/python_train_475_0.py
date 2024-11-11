R=range
S=str.split
I=input
L=S('Anka Chapay Cleo Troll Dracul Snowy Hexadecimal')
h={}
for i in R(7):h[L[i]]=i
d=[[]for i in R(9)]
for z in '0'*int(I()):a,_,b=S(I());d[h[a]]+=[h[b]]
a,b,c=map(int,S(I()))
o=[10**9,0]
def C(q,w,e,n):
    if n==7:
        if not(q and w and e):return
        p=[a/len(q),b/len(w),c/(len(e))];p=max(p)-min(p);l=sum(k in g for g in(q,w,e)for h in g for k in d[h]);global o
        if o[0]>p or o[0]==p and o[1]<l:o=p,l
    else:C(q+[n],w,e,n+1);C(q,w+[n],e,n+1);C(q,w,e+[n],n+1)
C([],[],[],0)
print(int(o[0]),o[1])