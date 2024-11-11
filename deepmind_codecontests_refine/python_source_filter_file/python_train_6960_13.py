w,h,n=map(int,input().split())
a1,a2,a3,a4=0,w,0,h
for i in range(n):
    x,y,a=map(int,input().split())
    if a==1:
        a1=max(a1,x)
    elif a==2:
        a2=min(a2,x)
    elif a==3:
        a3=max(a3,y)
    else:
        a4=min(a4,y)
print(max((a2-a1)*(a4-a3),0))