def answer():
    a = input().split()
    a = [int(x) for x in a]
    s = a[0]
    v1,v2 = a[1],a[2]
    t1,t2 = a[3],a[4]
    time1= (s/v1)+2*t1
    time2 = (s/v2)+2*t2
    if time1<time2:
        print("First")
    elif time1==time2:
        print("Friendship")
    else:
        print("Second")
answer()