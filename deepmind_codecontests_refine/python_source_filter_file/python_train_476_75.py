s,v1,v2,t1,t2=map(int,input().split())
if v1>=t1:
    r1=t1+s*v1+t1
else:
    r1=t1+s*v1+t1
if v2>=t2:
    r2=t2+s*v2+t2
else:
    r2=t2+(s)*v2+t2
print(r1,r2)
if r1<r2:
    print("First")
elif r1>r2:
    print("Second")
else:
    print("Freindship")
