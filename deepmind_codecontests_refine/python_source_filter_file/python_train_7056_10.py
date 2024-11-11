s,_,*q=open(0)
a='%s'
p=1
for q in q:
  try:
    q,f,c=q.split()
    if(f<'2')^p:a+=c
    else:a=c+a
  except:p^=1
print(a%s[:-1][::p or-1])