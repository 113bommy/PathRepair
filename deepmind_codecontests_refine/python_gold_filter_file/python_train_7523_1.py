input()
a={0}
c=t=0
for x in map(int,input().split()):
    t+=x
    if t in a:a={0,x};t=x;c+=1
    else:a.add(t)
print(c)