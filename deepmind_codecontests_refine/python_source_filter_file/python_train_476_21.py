s, v1, v2, t1, t2 = map(int,input().split())

if s*(v1-v2)+2*(t1-t2) > 0:
    print("First")
elif s*(v1-v2)+2*(t1-t2) < 0:
    print("Second")
else:
    print("Friendship")