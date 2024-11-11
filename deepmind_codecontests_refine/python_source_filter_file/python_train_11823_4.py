a,b,c=[int(x) for x in input().split()]
c=max(a,b,c)
if(c==a):
    d=max(b,c)
    
elif(c==b):
    d=max(a,c)
else:
    d=max(a,b)

s=abs(a-d)+abs(b-d)+abs(c-d)
print(s)