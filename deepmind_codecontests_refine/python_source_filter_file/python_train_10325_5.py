q=int(input())
w=list(map(int,input().split()))
e=sum(w)
r=max(w)
if e%2==0:
    if r>(e-r):
        print('NO')
    elif r<(e-r):
        print('YES')
else:
    print('NO')
