a,b=map(int,input().split())
c,d=map(int,input().split())
fl=0
if b==d:
    print(b)
else:
 for m in range(1,10010):
    if (c*m+d-c-b)%a==0 and (c*m+d-c-b)//a+1>0:
        print(c*m+d-c)
        fl=1
        break
 if fl==0:
    print(-1)
