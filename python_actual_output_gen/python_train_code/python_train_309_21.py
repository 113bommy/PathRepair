a,b,c=[int(i) for i in input().split()]
l=[]
s=[]
f=0
for i in range(1,10000):
    d=a*i
    e=b*i
    if(d<=c):
        l.append(d)
    if(e<=c):
        s.append(e)
    if(d>c and e>c):
        break
for  i in range(0,len(l)):
    if(l[i] in s):
        f=f+1
print(f)