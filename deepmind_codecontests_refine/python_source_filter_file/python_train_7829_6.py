for ctr in range(1):
    m=[input() for i in range(3)]
    x,y=m[0],m[2]
    m=list(zip(*m))
    p,q=m[0],m[2]
    flag=0
    if x==y or x==y[::-1] or x[::-1]==y:
        flag=1
    if p==q and p==q[::-1] or p[::-1]==q:
        flag=2
    if flag==2:
        print("YES")
    else:
        print("NO")
