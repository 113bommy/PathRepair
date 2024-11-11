n,x = map(int,input().split())
li = list(map(int,input().split()))
if(x-sum(li)==n-1):
    print('YES')
else:
    print('NO')
    
