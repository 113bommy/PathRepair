s,v1,v2,t1,t2=map(int,input().split())
time1=s*v1+t1
time2=s*v2+t2
if time1>time2:
    print("Second")
elif time1<time2:
    print("First")
elif time1==time2:
    print("Friendship")