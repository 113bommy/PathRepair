from itertools import*
s,k=open(0)
k,x=int(k),0
g=[len(list(v))for _,v in groupby(s)]
for c in g:x+=c//2
x*=k
if(s[0]==s[-2])*g[0]%2&g[-2]%2:x+=k//2if len(s)==g[0]else k-1
print(x)