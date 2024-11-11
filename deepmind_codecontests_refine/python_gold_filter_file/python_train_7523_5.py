input()
a={0}
c=s=0
for x in map(int,input().split()):
    s+=x
    if s in a:a={0,x};s=x;c+=1
    else:a.add(s)
print(c)