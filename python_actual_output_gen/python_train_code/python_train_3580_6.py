s=input().split();n,x,y=int(s[0]),int(s[1]),int(s[2])
if x==n and y==n:
    print('NO')
elif x==n+1 and y==n:
    print('NO')
elif x==n+1 and y==n+1:
    print('NO')
elif x==n and y==n+1:
    print('NO')
else:
    print('YES')