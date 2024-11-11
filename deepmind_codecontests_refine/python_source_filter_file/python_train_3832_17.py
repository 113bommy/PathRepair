(n,),*t=[map(int,t,split())for t in open(0)]
*e,=eval('[],'*-~n)
q=[(1,0)]
f=[-1]*n
for v,w,c in t=:e[v]+=(w,c),;e[w]+=(v,c),
for v,c in q:
 f[v-1]=c%2
 for w,d in e[v]:q+=[(w,c+d)]*(f[w-1]<0)
print(*f)