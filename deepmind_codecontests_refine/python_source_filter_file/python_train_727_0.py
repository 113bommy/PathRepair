input()
w=list(map(int,input().split()))
x=min(w)
m={k:v for k,v in zip(sorted(w),w)if k!=v}
l=list(m.keys())
p=[]
while l:
 a=l.pop();b=m[a];l.remove(b)
 if a==m[b]:p+=[[a,b]]
 else:
  t=[a,b]
  while 1:
   c=m[b];t+=[c]
   if c==a:p+=[t];break
   else:b=c;l.remove(c)
n=0
for s in p:
 n+=sum(s);t=len(s);y=min(s)
 if t>2:n+=min((t-2)*y,y+(t+1)*x)
print(n)
