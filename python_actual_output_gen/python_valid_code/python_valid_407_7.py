n=int(input())%360
v1=n//90
v2=v1+1
if v2<4:
    if n-90*v1>90*v2-n:
        print(v2)
    else:
        print(v1)
else:
    if n-90*v1<360-n:
        print(v1)
    else:
        print(v2)