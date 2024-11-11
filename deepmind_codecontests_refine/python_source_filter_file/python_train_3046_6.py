from collections import*
F=lambda:map(int,input().split())
v,=F()
for _ in[0]*v:s,b=F();f=Counter(x%b for x in F());
print(max(x and 1-x+b*f[x]for x in f))