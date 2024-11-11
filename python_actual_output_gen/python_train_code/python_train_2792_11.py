a,b=map(int,input().split())
if a+1//2<b:
    b=1+a-b
#print(a,b)
if a==b:
    k=(b-1)
else:
    k=(b-1)*2+(a-b)
print(k+1+2*a)