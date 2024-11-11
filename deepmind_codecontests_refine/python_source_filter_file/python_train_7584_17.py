d={}
d['a']=list(input())
d['b']=list(input())
d['c']=list(input())
now='a'
while True:
  if len(d[now])>1:
    now=d[now].pop(0)
  else:
    print(now.upper())
    exit()