a,b,c=map(int,input().split())
g=(c-b/a*100)/(100/a)
if int(g)!=g:g=int(g)+1
print(int(g))if g>0 else print(0)