s,v1,v2,t1,t2=map(int,input().split())
first=s*v1+t1*2
second=s*v2+t2*2
if first<second:
    print('First')
else:
    if second>first:
        print('Second')
    else:
        print('Friendship')
