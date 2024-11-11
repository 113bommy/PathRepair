


a,b,c = map(int,input().split())


if (a+b-c)%2==0 and (a-b+c)%2==0 and (b+c-a)%2==0 and (b+c-a)>=0 and (a-b+c)>=0 and (a+b-c)>=0:
    print((a+b-c)//2,(b+c-a)//2,(a-b+c)//2)
else:
    print('Impossible')
