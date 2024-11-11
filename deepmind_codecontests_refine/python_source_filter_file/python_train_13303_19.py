t1,t2=map(int, input().split())
a1,a2=map(int, input().split())
b1,b2=map(int, input().split())
a1*=t1
a2*=t2
b1*=t1
b2*=t2
if a1<b1:
    a1,a2,b1,b2=b1,b2,a1,a2
#a1>b2
if a1+a2==b1+b2:
    print('infinity')
    exit()

a1-=b1;b2-=a2
b2-=a1
if b2<0:
    print(0)
    exit()
ans=1+(a1//b2)*2
if a1%b2==0:
    ans+=1

print(ans)