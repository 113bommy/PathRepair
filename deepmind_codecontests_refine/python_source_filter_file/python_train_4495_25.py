s=input()
l=s.lower()
v=('a','e','i','o','u')
for i in l:
    if i in v:
        l=l.replace(i,"")
for i in l:
  print('.'+i,end="")
