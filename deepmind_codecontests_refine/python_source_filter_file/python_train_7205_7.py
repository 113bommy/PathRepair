a=int(input())
for i in range(a):
    a,b,c,n=map(int,input().split())
    if((a+b+c+n)%3!=0):
        print('NO')
    else:
        t=(a+b+c+n)//3
        if(t<=max(a,b,c)):
           print('NO')
        else:
            print('YES')
        
