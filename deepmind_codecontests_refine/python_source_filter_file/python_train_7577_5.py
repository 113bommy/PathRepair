N=int(input())
S=input()
x=0
r=1
m=10**9+7
for s in S:
    if s=='W':
        if x%2==1:
            x+=1
        elif x>0:
            r=(r*x)%m
            x-=1
        else:
            r=-1
            break
    else:
        if x%2==0:
            x+=1
        else:
            r=(r*x)%m
            x-=1
if r==-1:
    print(0)
else:
    a=1
    for i in range(N):
        a=a*(i+1)%m
    print((r*a)%m)