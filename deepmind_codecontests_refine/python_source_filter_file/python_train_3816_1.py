def okay(sl,r,c):
    rv  = [sl[i][j] for i in range(r) for j in range(c)]
    cv  = [sl[i][j] for j in range(c) for i in range(r)]
    for i in range(1,r*c):
        if i%r>0 and ((rv[i-1]=='S' and rv[i]=='W') or (rv[i-1]=='W' and rv[i]=='S')):
            return False
        if i%c>0 and ((cv[i-1]=='S' and cv[i]=='W') or (cv[i-1]=='W' and cv[i]=='S')):
            return False
    return True

r,c = list(map(int,input().split()))    #500,500
sl  = [input() for i in range(r)]
if okay(sl,r,c):
    print('YES')
    for s in sl:
        print(s.replace('.','D'))
else:
    print('NO')