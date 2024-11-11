n = int(input())
rob = [int(i) for i in input().split(' ')]
bio = [int(i) for i in input().split(' ')]

if rob == bio:
    print(-1)
elif(sum(rob) > sum(bio)):
    print(1)
else:
    rc = 0
    bc = 0
    for i, elem in enumerate(rob):
        if rob[i] < bio[i]:
            bc += 1
        elif rob[i] > bio[i]:
            rc += 1
    diff = bc - rc
    if rc == 0:
        print(-1)
    elif diff == 0:
        print(1)
    elif diff < 0:
        print(0)
    else:
        print(int(int(bc / rc) + 1))