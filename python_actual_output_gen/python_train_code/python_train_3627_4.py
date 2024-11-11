a,b=list(map(int,input().split()))



t=abs(a)+abs(b)



if a<0 and b>0:
    print(0,t,-t,0)
elif a>0 and b<0:
    print(0,-t,t,0)
elif a>0 and b>0:
    print(0,t,t,0)
else:
    print(-t,0,0,t)
