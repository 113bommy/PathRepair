s,v1,v2,t1,t2 = map(int,input().split())
x = v1*s+t1*2
y = v2*s+2*t2
if(x>y):
    print('First')
elif(x<y):
    print('Second')
else:
    print('Friendship')