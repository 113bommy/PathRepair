s,v1,v2,t1,t2=map(int,input().split())
f=s*v1+2*t1
se=s*v2+2*t2
if f>se:
    print("First")
elif se>f:
    print("Second")
else:
    print("Friendship")