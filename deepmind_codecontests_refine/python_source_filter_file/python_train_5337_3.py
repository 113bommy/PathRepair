import sys
t=int(sys.stdin.readline())
for _ in range(t):
    a=list(map(int,input().split()))
    e=0
    o=0
    ze=-1
    for i in range(len(a)):
        if a[i]%2==0:
            e+=1
        else:
            o+=1
        if a[i]==0 and i!=4:
            ze=i

    if e>=3 or (o>=3 and ze==-1):
        print('YES')
    else:
        print('NO')

 


