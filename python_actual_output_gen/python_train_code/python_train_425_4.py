s=input()
if len(s)%2==1:
    print(-1)
else:
    x,y=0,0
    for c in s:
        if c=='U':y+=1
        if c=='D':y-=1
        if c=='R':x+=1
        if c=='L':x-=1
    print(abs((x+y)//2))