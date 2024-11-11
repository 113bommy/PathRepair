t=int(input())
for i in range(t):
    s=input()
    s=s.split( )
    for e in s:
        s[s.index(e)]=int(e)
    if s[0]-s[1]<2:
        print('NO')
    elif ((s[0]-s[1])%2)==0 :
        print('YES')
    elif (s[0]-s[1]-3) >=0:
        print('YES')
    else:
        print('NO')
        
