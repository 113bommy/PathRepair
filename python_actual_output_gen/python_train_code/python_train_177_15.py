s,v1,v2,t1,t2 = [int(i) for i in input().split()]
t11 = s/v1
t22 = s/v2
t111 = t11+t1*2
t222 = t22+t2*2
if t111>t222:
    print('First')
elif t222>t111:
    print('Second')
else:
    print('Friendship')
