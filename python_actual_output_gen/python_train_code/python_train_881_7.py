a=int(input())
for i in range(a):
    p,q,r,s=map(int,input().split())
    if(p*r+q<s):
        print('NO')
        exit()
    t=s%r
    if(t>q):
        print('NO')
    else:
        print('YES')
        
