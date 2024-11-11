t=int(input())
for _ in range(0,t):
    n=int(input())
    l=list(map(int,input().split()))
    o=0
    for i in l:
        if(i%2!=0):
            o+=1
    if(o==n and n%2==0):
        print('N0')
    elif(o==0):
        print('NO')
    elif(o==n and n%2!=0):
        print('YES')
    elif(o%2==0 and o!=n):
        print('Yes')
    elif(o%2==1):
        print('YES')