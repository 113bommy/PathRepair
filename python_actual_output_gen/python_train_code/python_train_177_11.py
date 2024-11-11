s,v1,v2,t1,t2=map(int,input().split())
if 2*t1+v1 > 2*t2+v2:
    print("Second")
elif 2*t1+v1 < 2*t2+v2:
    print("First")
else:
    print("Friendship")