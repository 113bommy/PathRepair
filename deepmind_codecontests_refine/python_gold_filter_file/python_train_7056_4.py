s,_,*q=open(0)
a=['',s[:-1]]
p=1
for q in q:
  if q>'2':
    f=1if q<'2 2'else 0
    a[f^p]+=q[-2]
  else:p^=1
print(a[p^1][::-1]+a[p])