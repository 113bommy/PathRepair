s,_,*q=open(0)
a=['','']
p=1
for q in q:
  try:
    q,f,c=q.split()
    a[(f<'2')^p]+=c
  except:p^=1
print(a[p^1][::-1]+s[:-1][::p or-1]+a[p])