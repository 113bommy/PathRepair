x,y,z,t1,t2,t3 = map(int,input().split())
st = abs(x-y)*t1
et = (abs(x-y)+abs(x-z))*t2 + 3*t3

if(et < st):
    print("YES")
else:
    print("NO")
