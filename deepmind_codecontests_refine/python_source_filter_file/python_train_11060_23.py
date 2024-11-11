def call():
    n=int(input())
    n//=2
    if(n%2==1):
        print('NO')
        return
    print('YES')
    for i in range(1,n+1):
        print(i*2,end=" ")
    for i in range(1,n+1):
        print(i*2-1,end=" ")
    print(3*n-1)
    
    
for _ in range(int(input())):
    call()