from itertools import*
s,k=open(0)
k=int(k)
g=[len(list(v))for _,v in groupby(s)]
print(sum(c//2for c in g)*k+((s[0]==s[-2])*g[0]%2&g[-2]%2)*(k//2**(-len(s)==~g[0])-1))