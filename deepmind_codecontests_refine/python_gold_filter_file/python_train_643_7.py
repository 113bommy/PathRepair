n,x,y=map(int,input().split())
a,b,c,d=0,0,0,0
for i in range(n):
    s,t=map(int,input().split())
    if s<x:a+=1
    elif x<s:b+=1
    if y>t:c+=1
    elif t>y:d+=1
t=max(a,b,c,d)
print(t)
if a==t:
    print(x-1,y)
elif b==t:
    print(x+1,y)
elif c==t:
    print(x,y-1)
else:
    print(x,y+1)