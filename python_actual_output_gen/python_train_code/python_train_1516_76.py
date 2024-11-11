x,y,z,t1,t2,t3=map(int,input().split())

elv=(abs(x-z)*t2)+2*t3+(abs(x-y)*t2)+t3
stair=abs(x-y)*t1

if elv<stair:
    print("YES")
else:
    print("NO")