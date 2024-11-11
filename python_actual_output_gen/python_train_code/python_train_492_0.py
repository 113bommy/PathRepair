x,y=map(int,input().split())
dis=pow(abs(x),2)+pow(abs(y),2)
dis=pow(dis,0.5)
dis=abs(dis)
if dis==int(dis):
    print('black')
if x<0 and y<0 or x>0 and y>0:
    if (int(dis) % 2 == 0):
        print('black')
    else:
        print('white')
else:
    if(int(dis)%2!=0):
        print('black')
    else:
        print('white')