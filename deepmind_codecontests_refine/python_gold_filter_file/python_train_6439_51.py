a,b=map(lambda x:14 if int(x)==1 else int(x),input().split())
if a>b:s='Alice'
elif a<b:s='Bob'
else:s='Draw'
print(s)