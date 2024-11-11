s,v1,v2,t1,t2=map(int,input().split())
t=s*v1+t1*2
u=s*v2+t2*2
if t>u:
    print("First")
elif t<u:
    print("Second")
else:
    print("Friendship")