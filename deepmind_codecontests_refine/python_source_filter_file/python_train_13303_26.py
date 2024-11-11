T1,T2=map(int,input().split())
A1,A2=map(int,input().split())
B1,B2=map(int,input().split())
a,b,c,d=T1*A1,T1*B1,T2*A2,T2*B2
if a+c==b+d:
    print('infinity')
else:
    if (a-b)*(c-d)>0:
        print(0)
    else:
        x,y=abs(a-b),abs(a+c-b-d)
        if x%y==0:
            print(x//y*2)
        else:
            print(x//y*2+1)