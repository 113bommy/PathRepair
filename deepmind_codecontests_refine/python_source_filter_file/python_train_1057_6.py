x,y,z=map(int,input().split())
s,m=x//z,y//z
x%=z
y%=z
if (x+y)//z>1:
    print(s+m+1,min(z-x,z-y))
else:
    print(s+m,0)
    
